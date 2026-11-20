# Lab 03 – Wildcards, Hard Links and Symbolic Links

**Student ID:** e20230260  
**Student Name:** Heng Meylorng  
**Course:** Operating Systems  
**Lab:** 03

## 1. Objectives

- Understand how Bash wildcards select filenames.
- Understand the difference between hard links and symbolic links.
- Use inode numbers to identify hard links.
- Observe what happens when a file is renamed.
- Repair a dangling symbolic link using a relative path.

## 2. Wildcards

I practiced using Bash wildcard patterns to select filenames.

- `*` matches zero or more characters.
- `?` matches exactly one character.
- `[ ]` matches one character from a specified set.
- Quoting a wildcard prevents the shell from expanding it.

The results are saved in `evidence/wildcards.txt`.

## 3. Hard Links and Symbolic Links

I created two links for my original file, `stone.txt`.

- Hard link: `stone-hard.txt`
- Symbolic link: `stone-soft.txt`

Both the original file and hard link shared the same inode number (18752332). The symbolic link had its own inode number (18752388).

## 4. Rename Experiment

I renamed `stone.txt` to `stone-final.txt`.

- The hard link still accessed the original content, `version 873`.
- The symbolic link became dangling because its stored target was still `stone.txt`.

I then created a new `stone.txt` containing `version 921`.

The symbolic link worked again but accessed the new file, while the hard link continued to access the original content.

## 5. Repairing the Symbolic Link

I removed the old symbolic link and recreated it with the relative target `stone-final.txt`.

After repairing it, the symbolic link correctly accessed the original content, `version 873`.

I used a relative path because the link and its target are in the same directory.

## 6. Evidence

- `evidence/wildcards.txt`
- `evidence/links.txt`
- `evidence/replacement.txt`

## 7. Conclusion

Through this lab, I learned how Bash wildcards work and how hard links differ from symbolic links. I also learned that hard links refer to the same inode, while symbolic links store file paths. Renaming a target can break a symbolic link, and it can be repaired by updating its target path.

**Result:** 5/5 milestones passed.
