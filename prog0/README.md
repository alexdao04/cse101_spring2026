**TOWER OF HANOI** <br>
**CSE 101** <br>
**Prof. Alex Pang** <br>
**Alexander Dao** <br>
<br>
<br>
FROM THE TA LAB MATERIAL (THANK YOU IOANNIS)<br>
**Core Puzzle Idea** <br>
There are three pegs: A, B, and C. <br>
A move means taking the top disk from one peg and placing it on another peg.<br>
Only legal moves are allowed, based on the stacking rule of the selected mode.<br>
<br>
**General Requirements (All Modes)** <br>
Every printed move must represent a legal move from the current state.<br>
The internal state must remain consistent after each move.<br>
The final peg arrangement must match the goal condition of the selected mode.<br>
The output format must exactly match the format required by the assignment.<br>
<br>
**Mode 1: Standard** <br>
What the problem is<br>
 This is the classic Tower of Hanoi.<br>
Rule<br>
 1. A smaller disk may be placed on a larger disk.<br>
 2. A larger disk may never be placed on a smaller disk.<br>
Goal<br>
 Move all disks from peg A to peg C legally.<br>
Parameter meaning<br>
 k = number of disks.<br>
<br>
**Mode 2: Bicolor** <br>
What the problem is<br>
 Disks come in pairs that share the same physical size group.<br>
Rule<br>
1. A placement is legal if the moving disk’s size group is smaller than or equal to the size group of the disk currently on top of the destination peg.<br>
2. Placing a disk on another disk of the same size group is allowed.<br>
Goal<br>
 Move all disks to peg C while obeying the bicolor legality rule.<br>
Parameter meaning<br>
 k = number of pairs.<br>
<br>
**Mode 3: Monochrome (NOT IMPLEMENTED HERE)** <br>
What the problem is<br>
-This mode uses the same legal move behavior as bicolor, but has a different target arrangement.<br>
Rule<br>
 Use the same move legality as in bicolor mode.<br>
Goal<br>
Peg A ends empty.<br>
Odd-numbered disks end on peg B.<br>
Even-numbered disks end on peg C.<br>
The resulting stacks must still be legal.<br>
Parameter meaning<br>
 k = number of pairs.<br>
<br>
**Command-line format**<br>
Run the program with two arguments after the executable name:<br>
./prog0 <mode> <k> <br>
<br>
The meaning of k depends on the selected mode:<br>
·        Mode 1 — standard: k is the number of disks<br>
·        Mode 2 — bicolor: k is the number of pairs<br>
·        Mode 3 — monochrome: k is the number of pairs<br>
<br>
**Recursion: the core idea in standard Hanoi**<br>
A recursive function solves a problem by calling itself on a smaller version of the same problem. For standard Tower of Hanoi, to move n disks from peg A to peg C:<br>
·        Move n - 1 disks from A to B<br>
·        Move disk n from A to C<br>
·        Move n - 1 disks from B to C<br>
