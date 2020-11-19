this is a sentence on 'zd' branch that zd wrote at 11.00.

And this is added after 'zd' branch was created and the first push.

Git workflow https://www.atlassian.com/git/tutorials/comparing-workflows.
Based on this, I think we can just have one branch (master) and both work on this. General workflow is to
1. make local changes, add, commit.
2. git pull --rebase origin master # this pull any new changes made on remote since last sync to local repo. The reason to 'rebase' is that I guess we have a more or less linear working process than each of us working on a specific feature (at the moment...). 
3. git push origin master # this publish local changes to remote.

Or have a short-live branch:
1. git branch -b new-short-branch
2. make local changes, add, commit.
3. git checkout master # this moves us back to master branch (which will be the receiving branch)
4. git merge new-short-branch # presume that the new branch was very short so no new change has happened on remote master branch, then we can directly run 'merge'
5. git branch -d new-short-branch # delete the short-live branch as it won't be useful.

This is a test by Weiming using GitHub Desktop on Mac.  
GitHub Desktop just provides a Graphical User Interface(GUI), but essentially all functions can be achieved through command line.