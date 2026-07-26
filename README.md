# Note Editor Undo/Redo Stack

A small C program demonstrating the classic undo/redo pattern with two stacks.

## How it works

Two `Stack` instances are maintained:

- `undoStack` — holds actions that can be undone
- `redoStack` — holds actions that can be redone

Each stack is a fixed-size array (`MAX = 100`) of strings (up to 50 characters each). A `top` index tracks the current position; `-1` means empty.

## API

| Function | Description |
|---|---|
| `push(Stack *s, char item[50])` | Pushes a string onto the top of the stack. No-op if full. |
| `pop(Stack *s)` | Removes and returns the top string. Returns `NULL` if empty. |
| `isEmpty(Stack *s)` | Returns true when the stack holds no items. |
| `isFull(Stack *s)` | Returns true when the stack has reached `MAX`. |

## Example

```c
push(&undoStack, "Name1");
push(&undoStack, "Name3");
push(&undoStack, "Name5");

pop(&undoStack);   // "Name5"
```

Every new edit is pushed onto `undoStack`. When the user hits undo, the last action is popped off and pushed onto `redoStack`; redo reverses that movement.

## Build & run

```bash
gcc undo_redo_stack.c -o undo_redo_stack
./undo_redo_stack
```

## Limitations

- Educational example, not a full editor.
- `redoStack` is not yet wired to `undoStack`; undo does not currently move the popped action onto the redo stack.
- Stack capacity is fixed at compile time.
