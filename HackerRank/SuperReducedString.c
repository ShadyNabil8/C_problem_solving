typedef struct
{
    int top;
    int size;
    char *items;
} stack_t;
bool isFull(stack_t *stack)
{
    return stack->top == stack->size;
}
bool isEmpty(stack_t *stack)
{
    return stack->top == 0;
}
void push(stack_t *stack, char item)
{
    if (!isFull(stack))
    {
        stack->items[stack->top] = item;
        stack->top++;
    }
}
char pop(stack_t *stack)
{
    stack->top--;
    return stack->items[stack->top];
}
char get(stack_t *stack)
{
    return stack->items[stack->top - 1];
}
void stackInit(stack_t *stack)
{
    stack->items = (char *)calloc(stack->size, sizeof(char));
}
char *superReducedString(char *s)
{
    stack_t stack =
        {
            .items = NULL,
            .size = strlen(s),
            .top = 0};
    stackInit(&stack);
    for (int i = 0; i < stack.size; i++)
    {
        if (isEmpty(&stack))
        {
            push(&stack, s[i]);
        }
        else
        {
            if (get(&stack) == s[i])
            {
                printf("%c", pop(&stack));
            }
            else
            {
                push(&stack, s[i]);
                printf("pushed:%c\n", s[i]);
            }
        }
    }
    if (stack.top == 0)
    {
        return "Empty String";
    }
    else
    {
        char *str = (char *)calloc(stack.top, sizeof(char));
        for (int i = stack.top - 1; i >= 0; i--)
        {
            str[i] = pop(&stack);
        }
        return str;
    }
}