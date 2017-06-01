## fd_lib
This is my personal library of Pd. Any suggestions are more than welcome.
Enjoy!

## Get the library (first time only, or for a blank slate)
1. Click the green download-as-zip button above or do this from terminal:
	`$ git clone http://github.com/fdch/fd_lib fd_lib
2. Declare the library
	1. Put this object on a Pd patch
	`[declare -lib fd_lib -path fd_lib]
	1. OR: Put/send this message and replace "/path/to/" with your actual path and click it:
	`[;
	`pd path-dialog 1 1 +/path/to/fd_lib, save_preferences(
	1. OR: set the path from PREFERENCES>PATH dialog

## Compile the library

================================================================================

Thanks to the amazing Pd Lib Builder, you can simply do the following:

================================================================================

To compile the library run:

	$ make

To build the entire library in <fd_lib>

	$ make install

You can also compile single files, e.g., 

	$ make counter.pd_darwin
	
================================================================================

## OVERVIEW
1. Open the HELP>Browser (Cmd+b) or (ctrl+b) and navigate to the *fd_lib* entry

2. Use the ------navigator------ patch to use Cmd+Left|Right to go throught the patches.

3. Use/Edit whatever you want. See instructions below to push to the branch.

##GITHUB PUSHES ON BRANCH <0.01> (from terminal)

3. Initialize git
	`$ cd fd_lib
	`$ git init
4. Check what you have actually edited:
	`$ git status
5. Choose what you want to commit and add it like this
	`$ git add <file1>
	`$ git add <dir/file2>
6. Or choose All Files:
	`$ git add .
7. Describe briefly:
	`$ git commit -m "description"
8. Double check:
	`$ git remote add origin http://github.com/fdch/fd_lib
	`$ git remote -v
9. Push to the branch:
	`$ git push -u origin 0.01

## Issues
fch226 at nyu dot edu