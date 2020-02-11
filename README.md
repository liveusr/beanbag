# beanbag

## Quick git commands

- Configure your full name and email id to be recorded in any newly created commit
```
git config user.name "your name"
git config user.email "email_id@email.com"
```

- Configure default editor and difftool
```
git config --global core.editor vim
git config --global diff.tool vimdiff
```

- Clone a repository into a new directory
```
git clone https://github.com/liveusr/beanbag
--OR--
git clone https://github.com/liveusr/beanbag <optional local dir name>
```

- Show working tree status
```
git status
```

- Show changes
```
git diff
--OR--
git difftool
```

- Add all changes in working directory to the staging area
```
git add .
```

- Add any particular changed file to the staging area
```
git add <file name>
```

- Commit changes locally - opens new window to add commit log message
```
git commit
```

- Commit changes locally with one line commit message
```
git commit -m "commit message"
```

- Update commit message
```
git commit --amend
```

- Modify changes in last commit locally
```
<modify file(s)>
git add <file name(s)>
git commit --amend
```

- Undo last commit locally but keep file changes
```
git reset HEAD^
```

- Push local commits to remote master
```
git push -u origin master
```

- Remove/Undo last commit from remote
```
git reset HEAD^
git push -u origin +HEAD
```
