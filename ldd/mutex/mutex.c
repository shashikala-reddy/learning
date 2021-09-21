#include <linux/module.h>       //for modules loading and unloading
#include<linux/moduleparam.h>
#include <linux/fs.h>           //file operations
#include <linux/init.h>
#include <linux/cdev.h>         //character device
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kthread.h>	//thread
#include <linux/kernel.h> 
#include<linux/delay.h> //sleep
#include<linux/sched.h> //task struct
#include<linux/mutex.h>

MODULE_AUTHOR("Phani");
MODULE_LICENSE("GPL");


static struct task_struct *char_thread;
static struct task_struct *char_thread1;
struct mutex my_mutex;
int mydata=0;

int my_thread_fun(void *p);
int my_thread_fun(void *p)
{
	while(!kthread_should_stop())
	{
mutex_lock(&my_mutex);
mydata++;
	printk(KERN_INFO"my thread 1 is started %d",mydata);
mutex_unlock(&my_mutex);
msleep(1000);
	}
	return 0;
}

int my_thread_fun1(void *p);
int my_thread_fun1(void *p)
{
	while(!kthread_should_stop())
	{
mutex_lock(&my_mutex);
mydata++;
	printk(KERN_INFO"my thread 2 is started %d",mydata);
mutex_unlock(&my_mutex);
msleep(1000);
	}
	return 0;
}


static int __init my_simpledriver_init(void){

	printk(KERN_INFO"my sample driver start");
mutex_init(&my_mutex);	

	char_thread = kthread_run(my_thread_fun,NULL,"my_char_thread");
	if(char_thread){
		printk(KERN_INFO"kthread created successfully\n");
		//wake_up_process(char_thread);
	}
	else{
		printk(KERN_INFO"COuldnt create thread\n");
	}
	
	char_thread1 = kthread_run(my_thread_fun1,NULL,"my_char_thread 1");
	if(char_thread1){
		printk(KERN_INFO"kthread1 created successfully\n");
		//wake_up_process(char_thread);
	}
	else{
		printk(KERN_INFO"COuldnt create thread\n");
	}
	
	return 0;

}

module_init(my_simpledriver_init);

static void  __exit my_simpledriver_exit(void){

	printk(KERN_INFO"my sample driver exit");
	kthread_stop(char_thread);
	kthread_stop(char_thread1);


}

module_exit(my_simpledriver_exit);
