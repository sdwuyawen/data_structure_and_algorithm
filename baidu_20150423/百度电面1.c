void memcpy(unsigned char *src, unsigned char *dst, unsigned int len)
{
    unsigned int i;
    
    for(i = 0; i < len; i++)
    {
        *(dst + i) = *(src + i);
    }
}


void sort(int *array, int len)
{
    int i;
    int j;
    int temp;
    
    for(i = 0; i < len - 1; i++)
    {
        for(j = 0; j < len - 1 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void add(int a, int b)
{
    int val1;
    int val2
    
    while(1)
    {
        val1 = a ^ b;
        val2 = a & b;
        
        val2 <<= 1;
        
        val1 = val1 ^ val2;   
        
        if(val2 ==0)
        {
            break;
        }
    }
    
    return val1;

}