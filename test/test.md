this is a sentence on 'zd' branch that zd wrote at 11.00.

And this is added after 'zd' branch was created and the first push.

Git workflow https://www.atlassian.com/git/tutorials/comparing-workflows.
Based on this, I think we can just have one branch (master) and both work on this. General workflow is to
1. make local changes, add, commit.
2. git pull --rebase origin master # this pull any new changes made on remote since last sync to local repo. The reason to 'rebase' is that I guess we have a more or less linear working process than each of us working on a specific feature (at the moment...). 
3. git push origin master # this publish local changes to remote.