#!/bin/bash

authors=("alifaizyab8" "waqarwasif" "AnsharaAmir")

total_commits=0

# Calculate total commits
for author in "${authors[@]}"; do
    commits=$(git log --author="$author" --oneline | wc -l)
    total_commits=$((total_commits + commits))
done

# Print header
printf "%-15s %-8s %-12s %-10s %-12s\n" "Author" "Commits" "Insertions" "Deletions" "Contribution %"

# Loop through authors
for author in "${authors[@]}"; do
    commits=$(git log --author="$author" --oneline | wc -l)
    stats=$(git log --author="$author" --pretty=tformat: --shortstat | awk '
        /insertions/ {ins += $4; del += $6} 
        END {print ins, del}')
    insertions=$(echo $stats | awk '{print $1}')
    deletions=$(echo $stats | awk '{print $2}')
    percent=0
    if [ $total_commits -ne 0 ]; then
        percent=$(( commits * 100 / total_commits ))
    fi
    printf "%-15s %-8s %-12s %-10s %-12s\n" "$author" "$commits" "$insertions" "$deletions" "$percent%"
done
