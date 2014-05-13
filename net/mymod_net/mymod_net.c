#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/module.h>

static int
mynet_open(struct net_device *netdev)
{
	printk("mynet interface is up\n");
	netif_start_queue(netdev);
	return 0;
}

static int
mynet_stop(struct net_device *netdev)
{
	printk("mynet interface is down\n");
	netif_stop_queue(netdev);
	return 0;
}

static netdev_tx_t
mynet_xmit(struct sk_buff *skb, struct net_device *netdev)
{
	printk("mynet_xmit with data len %d\n", skb->len);
	netdev->stats.tx_packets++;
	netdev->stats.tx_bytes += skb->len;
        return NETDEV_TX_OK;
}

static const struct net_device_ops mynet_ops = {
	.ndo_open       = mynet_open,
	.ndo_stop       = mynet_stop,
        .ndo_start_xmit = mynet_xmit,
};


static struct net_device *mynet_dev;

static int __init
mymod_init (void)
{
	int rc;
	char mac[] = { 0xde, 0xad, 0xbe, 0xef, 0xba, 0xba };

	printk("Hello from my module!\n");
	if (!(mynet_dev = alloc_etherdev(0))) {
                return -ENOMEM;
        }

	mynet_dev->netdev_ops = &mynet_ops;
	memcpy(mynet_dev->dev_addr, mac, ETH_ALEN);
	memcpy(mynet_dev->perm_addr, mac, ETH_ALEN);

	if ((rc = register_netdev(mynet_dev))) {
		printk("register_netdev() returned %d\n", rc);
		return rc;
	}

	return 0;
}  

static void __exit
mymod_exit(void) 
{
	unregister_netdev(mynet_dev);
	printk("Goodbye from my module.\n"); 
}  

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_AUTHOR("Me"); 
MODULE_LICENSE("GPL"); 
MODULE_DESCRIPTION("Basic hello world-type module.");
