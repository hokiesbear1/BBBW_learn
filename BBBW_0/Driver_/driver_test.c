/**let's try something here*/

#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

// module init
static int __init first_driver_init(void)
{
    pr_info("first driver starts...\n");
    return 0;
}
// module ends
static void __exit first_driver_exit(void)
{
    pr_info("first driver ends...\n");
    return 0;
}

module_init(first_driver_init);
module_exit(first_driver_exit);
MUDLE_LICENSE("GPL");
MODULE_AUTHOR("HOKIESBEAR");
MODULE_DECRIPTION("A first driver");
MODULE_VERSION("0:1.0");

