void	printnode(t_stack *start)
{
	printf("\n");
       t_stack *temp;

        temp = start;
        while(temp)
        {
                printf("%ld \n", (long int)temp->nbr);
                temp = temp->next;
        }
		printf("\n");
}
