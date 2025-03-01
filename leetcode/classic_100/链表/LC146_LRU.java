import java.util.HashMap;

public class LC146_LRU {
    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // 缓存是 {1=1}
        lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
        lRUCache.put(1, 2); // 缓存是 {1=1, 2=2}

        lRUCache.get(1); // 返回 1
        lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        lRUCache.get(2); // 返回 -1 (未找到)
        lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        lRUCache.get(1); // 返回 -1 (未找到)
        lRUCache.get(3); // 返回 3
        lRUCache.get(4); // 返回 4

    }

    static class LRUCache {
        public class Dnode {
            Dnode prev;
            Dnode next;
            int val;
            int key;

            Dnode() {

            }

            Dnode(int key, int val) {
                this.key = key;
                this.val = val;
            }
        }

        void out() {
            Dnode o = ptr.next;
            for (; o != null;) {
                System.out.print(o.key + ":" + o.val + " ");
                o = o.next;
            }
            System.err.println();
        }

        HashMap<Integer, Dnode> store;
        Dnode ptr;
        Dnode tail;
        int cap = -1;
        int currCap = 0;

        public LRUCache(int capacity) {
            cap = capacity;
            store = new HashMap<Integer, Dnode>();
            ptr = new Dnode(-1, -1);
            tail = new Dnode(-2, -1);
            ptr.prev = null;
            ptr.next = tail;
            tail.prev = ptr;
            tail.next = null;
        }

        public int get(int key) {
            Dnode dnode = store.get(key);

            if (dnode != null) {
                // 补充连接
                Dnode prev = dnode.prev;
                Dnode next = dnode.next;
                prev.next = next;
                next.prev = prev;
                // 尾插
                Dnode tailPrev = tail.prev;
                insert(tailPrev, tail, dnode);
                store.put(key, dnode);
            } else if (store.get(key) == null) {
                return -1;
            }
            out();

            return store.get(key).val;
        }

        void insert(Dnode prev, Dnode next, Dnode dnode) {
            prev.next = dnode;
            next.prev = dnode;
            dnode.prev = prev;
            dnode.next = next;
        }

        public void put(int key, int value) {
            Dnode dnode = store.get(key);
            if (dnode != null) {
                dnode.val = value;
                // 补充连接
                Dnode prev = dnode.prev;
                Dnode next = dnode.next;
                prev.next = next;
                next.prev = prev;
                // 尾插
                Dnode tailPrev = tail.prev;
                insert(tailPrev, tail, dnode);
                store.put(key, dnode);
            } else {
                dnode = new Dnode(key, value);
                boolean isFull = (currCap == cap);
                // 长度判断
                if (isFull) {
                    Dnode remove = ptr.next;
                    Dnode newhead = ptr.next.next;
                    ptr.next = newhead;
                    newhead.prev = ptr;
                    // 删除淘汰
                    store.put(remove.key, null);
                }
                // 插入
                Dnode tailPrev = tail.prev;
                insert(tailPrev, tail, dnode);
                // 记录
                store.put(key, dnode);
                if (isFull == false) {
                    currCap += 1;
                }
            }
            out();
        }
    }
}
