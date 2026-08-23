#!/bin/bash

REPO_DIR="/Users/vaibhav/Desktop/Competitive-Programming"
INTERVAL=86400

cd "$REPO_DIR" || exit 1

echo "Auto-pull started. Checking for updates every 24 hours."
echo "Press Ctrl+C to stop."

while true; do
    OUTPUT=$(git pull 2>&1)
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $OUTPUT"
    sleep $INTERVAL
done
