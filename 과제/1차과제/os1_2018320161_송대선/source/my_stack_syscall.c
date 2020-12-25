#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/linkage.h>

#define MAXSIZE 500
 
int stack[MAXSIZE];
int top = -1;

int is_already_stacked; //the indictor variable which show if there is the same element as input 'a' in the stack
int pop_element; //the poped element
int stack_index; //index variable for 'for loop'

SYSCALL_DEFINE1(oslab_push, int, a){ //my push syscall function

	printk(KERN_INFO "[System Call] oslab_push(): ");
	is_already_stacked =0;	
	
	for (stack_index = 0; stack_index <= top; stack_index++){ //check if there is the same element as input 'a' in the stack
		if(a == stack[stack_index]){
			is_already_stacked = 1;
			break;
		}
	}
	

	if (is_already_stacked == 0){ //if there is no same elemet, then check whether stack is full
		if (top<MAXSIZE){
			//stack is not full, then push element 'a'.

			top++;
			stack[top] = a;
			printk("push %d\n", a);
			
			//print stack		
			printk("Stack Top -----------------\n");
			for (stack_index=top; stack_index>-1;stack_index--){
				printk("%d\n",stack[stack_index]);
			}
			
			printk("Stack Bottom --------------\n");
			return a;
		}
		else{
			//stack is full
			printk("Push %d", a);
			
			printk("Stack is full\n");

			//print stack		
			printk("Stack Top -----------------\n");
			for (stack_index=top; stack_index>-1;stack_index--){
				printk("%d\n",stack[stack_index]);
			}
			
			printk("Stack Bottom --------------\n");


			
			return a;
		}
	}
	else{
		//element 'a' is in the stack
		printk("Push %d", a);
		
		printk("element overlap\n");
		
		//print stack		
		printk("Stack Top -----------------\n");
		for (stack_index=top; stack_index>-1;stack_index--){
			printk("%d\n",stack[stack_index]);
		}
		
		printk("Stack Bottom --------------\n");

		return a;
	}
}

SYSCALL_DEFINE0(oslab_pop){ //my pop syscall function
	printk(KERN_INFO "[System Call] oslab_pop(): ");
	
	if (top>-1){ //check if the stack is empty
		
		//pop element
		pop_element = stack[top];
		top--;

		printk("pop %d\n", pop_element);
		
		//print stack		
		printk("Stack Top -----------------\n");
		for (stack_index=top; stack_index>-1; stack_index--){
			printk("%d\n",stack[stack_index]);
		}
		
		printk("Stack Bottom --------------\n");
		
		return pop_element;
	}
	else{
		// if stack is empty, then return -1
		printk("stack is empty");
		
		//print stack		
		printk("Stack Top -----------------\n");
		for (stack_index=top; stack_index>-1;stack_index--){
			printk("%d\n",stack[stack_index]);
		}
		
		printk("Stack Bottom --------------\n");
		
		return -1;
	}
}
