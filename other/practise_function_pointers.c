void f(void)
{
    /* do nothing */
}

int main(void)
{
    void (*p)(void);

    p = f;
    p();
}
