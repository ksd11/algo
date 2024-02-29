
class Node:
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

class MyLinkedList:

    def __init__(self):
        self.head = None
        self.size = 0

    def __get_node(self, index: int) -> Node:
        if index < 0 or index >= self.size:
            return None

        if index < self.size - index:
            # 从前往后找
            idx = 0
            node = self.head
            while idx < index:
                idx += 1
                node = node.next
        else:
            # 从后往前找
            idx = self.size - 1
            node = self.head.prev
            while idx > index:
                idx -= 1
                node = node.prev
        return node

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        
        return self.__get_node(index).val

    def addAtHead(self, val: int) -> None:
        if self.size == 0:
            self.head = Node(val)
            self.head.next = self.head
            self.head.prev = self.head
        else:
            node = Node(val, self.head, self.head.prev)
            self.head.prev.next = node
            self.head.prev = node
            self.head = node
        self.size += 1

    def addAtTail(self, val: int) -> None:
        if self.size == 0:
            self.head = Node(val)
            self.head.next = self.head
            self.head.prev = self.head
        else:
            node = Node(val, self.head, self.head.prev)
            self.head.prev.next = node
            self.head.prev = node
        self.size += 1

    
    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        
        if index == 0:
            self.addAtHead(val)
        elif index == self.size:
            self.addAtTail(val)
        else:
            node = self.__get_node(index)
            new_node = Node(val, node, node.prev)
            node.prev.next = new_node
            node.prev = new_node
            self.size += 1
    
    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        
        if self.size == 1:
            self.head = None
        else:
            node = self.__get_node(index)
            node.prev.next = node.next
            node.next.prev = node.prev
            if index == 0:
                self.head = node.next
        self.size -= 1