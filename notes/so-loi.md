
# So Lo i - Common Programming Mistakes

## 1. Dereferencing an invalid pointer

**Problem:**
Using a pointer before initializing it or after
its target memory is no longer valid.

**Prevention:**
- Initialize pointers before using them.
- Check for NULL when appropriate.
- Do not access memory after free().

## 2. Buffer overflow

**Problem:**
Writing data beyond the allocated buffer size.

**Prevention:**
- Always track buffer capacity.
- Check array boundaries before writing.
- Use functions with explicit size limits.

## 3. Incorrect pointer and array handling

**Problem:**
Confusing an array with a pointer or calculating
the wrong number of elements.

**Prevention:**
- Understand the difference between arrays and pointers.
- Pass the array length explicitly to functions.
- Check pointer arithmetic carefully.

## 4. Incorrect memory management

**Problem:**
Forgetting to free dynamically allocated memory
or using memory after it has been freed.

**Prevention:**
- Match malloc() with free().
- Check the return value of malloc().
- Avoid using pointers after free().
