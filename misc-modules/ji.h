/*
 * =====================================================================================
 *
 *       Filename:  ji.h
 *
 *    Description:  Define common macro.
 *
 *        Version:  1.0
 *        Created:  2017年08月07日 11时15分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bo Du (), bodu402@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


/*
 * Define seq_operations for show function, 
 * using single_open to call show just one time.
 * */
#undef DEFINE_SINGLE_SEQOPS
#define DEFINE_SINGLE_SEQOPS(show)	\
static int show##_open(struct inode *inode, struct file *file)	\
{	\
	return single_open(file, show, PDE_DATA(inode));	\
}	\
static struct file_operations show##_proc_fops = {	\
	.owner = THIS_MODULE,	\
	.open = show##_open,	\
	.read = seq_read,	\
	.llseek = seq_lseek,	\
	.release = single_release	\
}

#undef create_proc_read_entry
#define create_proc_read_entry(name, mode, parent, show, data)	\
do {	\
	if (!proc_create_data(name, mode, parent, &show##_proc_fops, data))	\
		pr_warn(name ": create proc file failed.");	\
} while(0)
