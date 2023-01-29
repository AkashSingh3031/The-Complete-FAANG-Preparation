class Heap<T> {
  private list: (T | null)[];
  private comparator: (a: T, b: T) => number;
  constructor(comparator: (a: T, b: T) => number) {
    this.comparator = comparator;
    this.list = [];
    this.list.push(null);
  }
  add(val: T): boolean {
    let prevSize = this.list.length;
    this.list.push(val);
    let i = this.list.length - 1;
    while (i > 1) {
      let parentindex = i / 2;
      let compare = this.comparator(this.list[i]!, this.list[parentindex]!);
      if (compare > 1) {
        let temp = this.list[i];
        this.list[i] = this.list[parentindex];
        this.list[parentindex] = temp;
        i = parentindex;
      } else break;
    }
    return this.size - prevSize == 1;
  }
  extract(): T | undefined|null {
    if (this.list.length == 1) return undefined;
    if (this.list.length == 2) {
      let deleted = this.list.pop();
      return deleted;
    }
    let [first, deleted, ...rest] = this.list;
    let lastElem = rest.pop();
    this.list = [first, lastElem!, ...rest];
    let i = 1;
    while (i < this.list.length - 1) {
      let leftIndex = 2 * i;
      let rightIndex = 2 * i + 1;
      let index = i;
      if (
        leftIndex < this.list.length &&
        this.comparator(this.list[leftIndex]!, this.list[index]!) > 0
      ) {
        index = leftIndex;
      }
      if (
        rightIndex < this.list.length &&
        this.comparator(this.list[rightIndex]!, this.list[index]!) > 0
      ) {
        index = rightIndex;
      }
      if (index != i) {
        let temp = this.list[index];
        this.list[index] = this.list[i];
        this.list[i] = temp;
        i = index;
      } else break;
    }
    return deleted;
  }
  peek(): T | undefined| null{
    return this.list.length == 1 ? undefined : this.list[1];
  }
  get size(): number {
    return this.list.length - 1;
  }
}

const heap = new Heap<number>((a, b) => a - b);
heap.add(54);
heap.add(24);
heap.add(4);
heap.add(99);
heap.add(45);
heap.add(93);
console.log(heap.size);
console.log(heap.peek());
while (heap.size) {
  console.log("extracted -> " + heap.extract());
}
console.log(heap.size);
