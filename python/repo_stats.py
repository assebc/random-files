#!/usr/bin/env python3
import os
import argparse

DEFAULT_EXCLUDES = {".git", "node_modules", "dist", "build", "out", ".next", ".cache"}

TARGET_SUFFIXES = {
    ".component.ts": "component_ts",
    ".component.html": "component_html",
    "service.ts": "service_ts",
    ".module.ts": "module_ts",
}

def is_binary_file(path, chunk_size=1024):
    """Heuristic binary check: if file contains null bytes, treat as binary."""
    try:
        with open(path, "rb") as f:
            chunk = f.read(chunk_size)
        return b"\x00" in chunk
    except Exception:
        return True

def count_loc(path):
    """Count LOC in a text file safely."""
    try:
        with open(path, "r", encoding="utf-8", errors="ignore") as f:
            return sum(1 for _ in f)
    except Exception:
        return 0

def should_exclude_dir(dir_name, excludes):
    return dir_name in excludes

def main():
    parser = argparse.ArgumentParser(
        description="Count files, LOC, and specific Angular-ish file patterns in a repo."
    )
    parser.add_argument(
        "repo_path",
        nargs="?",
        default=".",
        help="Path to the repo directory (default: current directory)."
    )
    parser.add_argument(
        "--exclude",
        action="append",
        default=[],
        help="Directory name to exclude (can be used multiple times)."
    )
    args = parser.parse_args()

    repo_path = os.path.abspath(args.repo_path)
    excludes = set(DEFAULT_EXCLUDES) | set(args.exclude)

    total_files = 0
    total_loc = 0
    suffix_counts = {k: 0 for k in TARGET_SUFFIXES.values()}

    for root, dirs, files in os.walk(repo_path):
        # modify dirs in-place so os.walk doesn't descend into excluded dirs
        dirs[:] = [d for d in dirs if not should_exclude_dir(d, excludes)]

        for filename in files:
            filepath = os.path.join(root, filename)

            # Count file
            total_files += 1

            # Match suffix categories
            for suffix, label in TARGET_SUFFIXES.items():
                if filename.endswith(suffix):
                    suffix_counts[label] += 1

            # LOC counting (skip binaries)
            if not is_binary_file(filepath):
                total_loc += count_loc(filepath)

    print("\n=== Repo Stats ===")
    print(f"Repo path: {repo_path}")
    print(f"Excluded dirs: {', '.join(sorted(excludes))}\n")

    print(f"Total files: {total_files}")
    print(f"Total LOC:   {total_loc}\n")

    print("=== Specific file counts ===")
    print(f"*.component.ts:   {suffix_counts['component_ts']}")
    print(f"*.component.html: {suffix_counts['component_html']}")
    print(f"*service.ts:      {suffix_counts['service_ts']}")
    print(f"*.module.ts:      {suffix_counts['module_ts']}")
    print()

if __name__ == "__main__":
    main()
