#!/usr/bin/env python3
"""Generate a unique fingerprint code for all work in a GitHub repository."""

from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
from dataclasses import asdict, dataclass
from pathlib import Path


@dataclass
class RepoFingerprint:
    repository: str
    branch: str
    commit_count: int
    latest_commit: str
    fingerprint: str


def run_git(args: list[str], repo_path: Path) -> str:
    result = subprocess.run(
        ["git", *args],
        cwd=repo_path,
        check=True,
        text=True,
        capture_output=True,
    )
    return result.stdout.strip()


def build_fingerprint(repo_path: Path) -> RepoFingerprint:
    repo_name = repo_path.resolve().name
    branch = run_git(["rev-parse", "--abbrev-ref", "HEAD"], repo_path)
    latest_commit = run_git(["rev-parse", "HEAD"], repo_path)

    commit_list = run_git(["rev-list", "--all"], repo_path).splitlines()
    commit_count = len(commit_list)

    signature_material = {
        "repository": repo_name,
        "branch": branch,
        "latest_commit": latest_commit,
        "all_commits": commit_list,
    }

    payload = json.dumps(signature_material, sort_keys=True).encode("utf-8")
    digest = hashlib.sha256(payload).hexdigest().upper()
    code = f"EUROPA-{digest[:8]}-{digest[8:16]}-{digest[16:24]}"

    return RepoFingerprint(
        repository=repo_name,
        branch=branch,
        commit_count=commit_count,
        latest_commit=latest_commit,
        fingerprint=code,
    )


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Create a stable unique code representing all Git history in the repository."
    )
    parser.add_argument("--repo", default=".", help="Path to the Git repository.")
    parser.add_argument(
        "--json",
        action="store_true",
        help="Output only JSON (useful for CI/CD pipelines).",
    )
    parser.add_argument(
        "--output",
        help="Optional file path where JSON result will be written.",
    )
    args = parser.parse_args()

    repo_path = Path(args.repo)
    fp = build_fingerprint(repo_path)
    data = asdict(fp)

    if args.output:
        out_path = Path(args.output)
        out_path.parent.mkdir(parents=True, exist_ok=True)
        out_path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")

    if args.json:
        print(json.dumps(data, indent=2))
        return

    print("Repository:", fp.repository)
    print("Branch:", fp.branch)
    print("Commits:", fp.commit_count)
    print("Latest commit:", fp.latest_commit)
    print("Unique code:", fp.fingerprint)


if __name__ == "__main__":
    main()
