Note Editor Undo/Redo Stack

A simple C program that demonstrates the classic undo/redo pattern using two stacks.

How it works

- Two separate Stack instances are maintained:
  - undoStack — holds actions that can be undone.
  - redoStack — holds actions that can be redone.
- Each Stack is a fixed-size array (MAX = 100) of strings (max 50 characters each), with a top index tracking the current position (-1 means empty).
- push(Stack *s, char chracter[50]) adds a new string to the top of a stack (no-op if the stack is full).
- pop(Stack *s) removes and returns the string at the top of a stack (returns NULL if the stack is empty).
- isEmpty / isFull are helper checks used internally by push/pop.

Example flow (main)

push(&undoStack, "Name1");
push(&redoStack, "Name2");
push(&undoStack, "Name3");
push(&redoStack, "Name4");
push(&undoStack, "Name5");

pop(&undoStack);  // prints "Name5"
pop(&redoStack);  // prints "Name4"

This simulates how a text/note editor could track edit history: every new action is pushed onto undoStack; when the user hits "undo," the last action is popped off; if they then "redo," it would be pushed onto/popped from redoStack in a real implementation.

Build & run

gcc undo_redo_stack.c -o undo_redo_stack
./undo_redo_stack

Notes

- This is a minimal/educational example, not a full editor — redoStack isn't yet wired up to actually restore undone actions.
- Fixed a typo where redoStack was mistakenly referenced as rendoStack in several places.
