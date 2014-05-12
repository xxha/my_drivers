test module param by book.ko:

sudo insmod book.ko book_name=hello num=1000
sudo rmmode book

dmesg |tail -10
or
cat /sys/module/book/parameters/book_name
cat /sys/module/book/parameters/num


