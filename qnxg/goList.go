package main

import "fmt"

type Node struct {
	x   int
	pre *Node
	nxt *Node
}

var head, tail *Node

func addElement(i, x int) {
	// 在 i 位置后加入值为 x 的节点，索引由 1 开始
	now := head
	for j := 0; j < i; j++ {
		now = (*now).nxt
	}
	if now == nil {
		now = tail
	}
	if head == nil && tail == nil {
		now := new(Node)
		(*now).x = x
		head = now
		tail = now
	} else if head == tail {
		det := new(Node)
		(*det).x = x
		(*head).nxt = det
		(*det).pre = head
		tail = det
	} else {
		nxt := (*now).nxt
		det := new(Node)
		(*det).x = x
		(*now).nxt = det
		(*nxt).pre = det
		(*det).pre = now
		(*det).nxt = nxt
	}
	return
}

func delElement(i int) {
	// 删除 i 位置节点
	now := head
	for j := 0; j < i; j++ {
		now = (*now).nxt
	}
	pre := (*now).pre
	nxt := (*now).nxt
	(*pre).nxt = nxt
	(*nxt).pre = pre
	// 不需要释放 now 的内存吗？
}

func getElement(i int) int {
	// 返回 i 位置节点的值
	now := head
	for j := 0; j < i; j++ {
		now = (*now).nxt
	}
	return (*now).x
}

func main() {
	/* 输入格式说明：
	输入 1 i x 表示插入操作，在 i 位置之后插入值为 x 的节点
	输入 2 i 表示删除操作，删除 i 位置的元素
	输入 3 i 表示查询操作，输出 i 位置元素的值
	输入 -1 表示结束程序
	输入其他值无效（等待下次输入）
	*/
	for {
		var opt int
		fmt.Scan(&opt)
		if opt == 1 {
			var i, x int
			fmt.Scanln(&i, &x)
			addElement(i, x)
		} else if opt == 2 {
			var i int
			fmt.Scanln(&i)
			delElement(i)
		} else if opt == 3 {
			var i int
			fmt.Scanln(&i)
			fmt.Println(getElement(i))
		} else if opt == -1 {
			return
		} else {
			fmt.Scan(&opt)
		}
	}
	return
}
