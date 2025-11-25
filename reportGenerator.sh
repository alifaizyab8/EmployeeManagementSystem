#!/bin/bash

# 1. Define the authors to track
authors=("alifaizyab8" "waqarwasif" "AnsharaAmir")

# Initialize arrays to store data so we don't have to run git commands twice
declare -a author_commits
declare -a author_insertions
declare -a author_deletions

total_group_commits=0

echo "Calculating statistics..."

# 2. Loop through authors to gather data
for i in "${!authors[@]}"; do
    author="${authors[$i]}"
    
    # Get Commit Count
    # --all: looks at all branches, not just the current one
    # --no-merges: excludes merge commits (optional, usually gives cleaner stats)
    count=$(git log --author="$author" --all --no-merges --oneline | wc -l)
    
    # Store commit count in array and add to total
    author_commits[$i]=$count
    total_group_commits=$((total_group_commits + count))

    # Get Insertions and Deletions
    # --numstat: gives strict number columns (added deleted filename)
    # awk: sums column 1 (inserts) and column 2 (deletes). Ignores binary files ("-").
    stats=$(git log --author="$author" --all --no-merges --pretty=tformat: --numstat | \
    awk '
        $1 != "-" && $2 != "-" { 
            ins += $1; 
            del += $2 
        } 
        END { 
            print ins+0, del+0 
        }
    ')

    # Store stats in arrays
    author_insertions[$i]=$(echo "$stats" | cut -d ' ' -f1)
    author_deletions[$i]=$(echo "$stats" | cut -d ' ' -f2)
done

# 3. Print the Header
echo "------------------------------------------------------------------------"
printf "%-15s %-10s %-12s %-12s %-15s\n" "Author" "Commits" "Insertions" "Deletions" "Contribution %"
echo "------------------------------------------------------------------------"

# 4. Print the Data
for i in "${!authors[@]}"; do
    author="${authors[$i]}"
    commits="${author_commits[$i]}"
    insertions="${author_insertions[$i]}"
    deletions="${author_deletions[$i]}"
    
    # Calculate percentage (based on total commits of this group)
    if [ "$total_group_commits" -gt 0 ]; then
        # Floating point calculation using awk for precision
        percent=$(awk "BEGIN {printf \"%.1f\", ($commits * 100) / $total_group_commits}")
    else
        percent="0.0"
    fi

    # Print formatted row
    printf "%-15s %-10s %-12s %-12s %-15s\n" "$author" "$commits" "$insertions" "$deletions" "$percent%"
done

echo "------------------------------------------------------------------------"
echo "Total Commits by Group: $total_group_commits"
