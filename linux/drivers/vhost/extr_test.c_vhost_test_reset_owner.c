#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct vhost_umem {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  mutex; } ;
struct vhost_test {TYPE_1__ dev; } ;

/* Variables and functions */
 long ENOMEM ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 long vhost_dev_check_owner (TYPE_1__*) ; 
 int /*<<< orphan*/  vhost_dev_reset_owner (TYPE_1__*,struct vhost_umem*) ; 
 struct vhost_umem* vhost_dev_reset_owner_prepare () ; 
 int /*<<< orphan*/  vhost_dev_stop (TYPE_1__*) ; 
 int /*<<< orphan*/  vhost_test_flush (struct vhost_test*) ; 
 int /*<<< orphan*/  vhost_test_stop (struct vhost_test*,void**) ; 

__attribute__((used)) static long vhost_test_reset_owner(struct vhost_test *n)
{
	void *priv = NULL;
	long err;
	struct vhost_umem *umem;

	mutex_lock(&n->dev.mutex);
	err = vhost_dev_check_owner(&n->dev);
	if (err)
		goto done;
	umem = vhost_dev_reset_owner_prepare();
	if (!umem) {
		err = -ENOMEM;
		goto done;
	}
	vhost_test_stop(n, &priv);
	vhost_test_flush(n);
	vhost_dev_stop(&n->dev);
	vhost_dev_reset_owner(&n->dev, umem);
done:
	mutex_unlock(&n->dev.mutex);
	return err;
}