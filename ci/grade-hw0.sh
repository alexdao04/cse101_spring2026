#!/usr/bin/env bash
set -euo pipefail

SUBMISSION_DIR="${1:-hw0}"

if [ ! -d "$SUBMISSION_DIR" ]; then
  echo "Submission directory not found: $SUBMISSION_DIR"
  exit 1
fi

echo "== HW0 Visible Grader =="

echo "== Files =="
ls -la "$SUBMISSION_DIR"

echo "== Build =="
if [ -f "$SUBMISSION_DIR/Makefile" ] || [ -f "$SUBMISSION_DIR/makefile" ]; then
  make -C "$SUBMISSION_DIR"
else
  gcc "$SUBMISSION_DIR/main.c" -o "$SUBMISSION_DIR/main"
fi

echo "== Run =="
"$SUBMISSION_DIR/main" | tee "$SUBMISSION_DIR/output.txt"

echo "== Result =="
test "$(tr -d '\n\r' < "$SUBMISSION_DIR/output.txt")" = "42"
echo "PASS"