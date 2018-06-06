# Game and Save Menu
Graphical game save and selction menu based on graphics.h

follow the steps provided to add the grsphics headers and build options
for code::blocks

http://www.codeblocks.org/downloads/26


# 1. Download Code::Blocks and Copy Files

	1. Download the zip file in master
	2. Exact all files from the zip.
	3. Install the 'codeblocks-13.12mingw-setup.exe'.
	4. Open the folder that stores the files from the zip
	5. Copy the two files Graphic.h and Winbgim.h 
	4. After successful install, Open Installed file locataion of CodeBlocks. Make a sure CodeBlocks is closed totally.
				   (64bit PC) C:\Program Files (x86)\CodeBlocks
				   (32bit PC) C:\Program Files\CodeBlocks
	7. Open MinGW folder.
	8. Now paste the two files to include folder.
	9. Again go to the folder and copy libbgi.a 
	10. Paste it to lib folder.

# 2. Set Up Linker Settings in Code::Blocks

	11. Now open CodeBlock.
	12. Open Settings => Compiler
	13. Then go to 'Linker settings'.
	14. Here you will see 2 box. 
	15. copy+paste below words to 'Other linker option' (Right side box).			
			-lbgi -lgdi32 -luser32

	16. And for left side (Link Libraries) : click on 'Add' and then '...'
	17. Find the libbgi.a file that you have already pasted before.
		 Default location:
				   (64bit PC) C:\Program Files (x86)\CodeBlocks\MinGW\lib 
				   (32bit PC) C:\Program Files\CodeBlocks\MinGW\lib
	18. Now click to OK,OK.
	
	19. Now your CodeBlocks is ready to complile graphics.h
	
	20. Open 'game.cpp' to CodeBlocks and try to compile it.

# 3. Change The Titles, Colors or Add a Game

        I have created many comments so changing the code shall be easiest if necessary
	
	also check out this site for more help on modules of graphics.h
	
	https://www.programmingsimplified.com/c/graphics.h

 
	
