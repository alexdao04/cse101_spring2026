**TOWER OF HANOI\n** 
**CSE 101\n**
**Prof. Alex Pang\n**
**Alexander Dao\n**

Core Puzzle Idea 
There are three pegs: A, B, and C.
A move means taking the top disk from one peg and placing it on another peg.
Only legal moves are allowed, based on the stacking rule of the selected mode.

General Requirements (All Modes) 
Every printed move must represent a legal move from the current state.
The internal state must remain consistent after each move.
The final peg arrangement must match the goal condition of the selected mode.
The output format must exactly match the format required by the assignment.

Mode 1: Standard 
What the problem is
 This is the classic Tower of Hanoi.
Rule
 1. A smaller disk may be placed on a larger disk.
 2. A larger disk may never be placed on a smaller disk.
Goal
 Move all disks from peg A to peg C legally.
Parameter meaning
 k = number of disks.

Mode 2: Bicolor 
What the problem is
 Disks come in pairs that share the same physical size group.
Rule
1. A placement is legal if the moving disk’s size group is smaller than or equal to the size group of the disk currently on top of the destination peg.
2. Placing a disk on another disk of the same size group is allowed.
Goal
 Move all disks to peg C while obeying the bicolor legality rule.
Parameter meaning
 k = number of pairs.

Mode 3: Monochrome 
What the problem is
-This mode uses the same legal move behavior as bicolor, but has a different target arrangement.
Rule
 Use the same move legality as in bicolor mode.
Goal
Peg A ends empty.
Odd-numbered disks end on peg B.
Even-numbered disks end on peg C.
The resulting stacks must still be legal.
Parameter meaning
 k = number of pairs.
