#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/unistd.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/syscalls.h>

MODULE_LICENSE("GPL");

int id = 0;
module_param(id,int,0);

static void __exit func2(void){
    printk("Exiting the program\n");
}

static int  __init func(void){
    struct task_struct *search;
    search = pid_task(find_vpid(id),PIDTYPE_PID);

    if(search == NULL){
        printk("Invalid Input\n");
        return -1;
    }

    printk("process ID : %d\n path : %s\n", search->pid, search->comm);
    printk("UID : %d\n",search->cred->uid.val);
    printk("Group ID : %d\n",search->group_leader->pid);
    return 0;
}

module_init(func);
module_exit(func2);