
public class SLLSet {
	private int size;
	private SLLNode head;

	public SLLSet() {
		head = null;
		size = 0;
	}

	public SLLSet(int[] sortedArray) {
		size = sortedArray.length;     
		head = new SLLNode(sortedArray[0], null);   
		SLLNode current = head;        

		for (int i = 1; i < size; i++) {
			current.next = new SLLNode(sortedArray[i], null); 
			current = current.next;       
		}
	}

	public int getSize() {

		return size;
	}

	public SLLSet copy() {
		SLLNode current = head;
		int[] arr = new int[size];   
		for (int i = 0; i < size; i++) {
			arr[i] = current.value;  
			current = current.next;
		}

		for (int i = 0; i < arr.length - 1; i++) {
			for (int j = 0; j < arr.length - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) { 
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;    
				}
			}
		}

		SLLSet aCopy = new SLLSet(arr);


		return aCopy;
	}

	public boolean isIn(int v) {
		SLLNode current = head;

		while (current != null) {  
			if (current.value == v) {
				return true;
			}

			current = current.next;
		}

		return false;
	}

	public void add(int v) {
		if (head == null) { 
			head = new SLLNode(v, null);
			size = 1;   
		} else {  
			if (v < head.value) {  
				head = new SLLNode(v, head); 
				size++;
			} else 
			{
				SLLNode current = head;
				SLLNode prev = null;

				while (current != null && v > current.value) {
					prev = current;   
					current = current.next;
				}

				if (current == null) {
					prev.next = new SLLNode(v, null);
					size++;
				} else if (current.value != v) {
					prev.next = new SLLNode(v, current);
					size++;
				}
			}
		}
	}

	public void remove(int v) {
		if (head == null)
			return;

		if (head.value == v) { 
			head = head.next;
			size--;   
			return;
		}

		SLLNode current = head; 
		SLLNode prev = null;

		while (current != null && current.value != v) { 
			prev = current;    
			current = current.next;
		}

		if (current != null) {
			prev.next = current.next;
			size--;
		}
	}

	public SLLSet union(SLLSet s) {
		
		if (s.head == null) 
			return this;

		if (this.head == null)
			return s;

		SLLSet newSet = s.copy(); 	
		SLLNode current = this.head;
		while(current != null) {
			newSet.add(current.value);  
			current = current.next;
		}
		return newSet;
	}

	public SLLSet intersection(SLLSet s) {
		SLLSet interSet = new SLLSet();

		if (s.head == null || this.head == null)   
			return interSet;

		SLLNode thisCurrent = this.head;
		SLLNode otherCurrent = s.head;

		while (thisCurrent != null && otherCurrent != null) {
			if (thisCurrent.value < otherCurrent.value) {  
				thisCurrent = thisCurrent.next;
			} else if (thisCurrent.value > otherCurrent.value) {
				otherCurrent = otherCurrent.next;
			} else if (thisCurrent.value == otherCurrent.value) {
				interSet.add(thisCurrent.value);
				thisCurrent = thisCurrent.next;
				otherCurrent = otherCurrent.next;
			}
		}

		return interSet;
	}

	public SLLSet difference(SLLSet s) {
		SLLSet diffset = new SLLSet();
		diffset.head = new SLLNode(0,null);
		SLLNode current_diff =diffset.head;
		SLLNode current_this =this.head;
		while (current_this !=null) {
			if (!s.isIn(current_this.value)) { 
				current_diff.next = new SLLNode(0,null);
				current_diff = current_diff.next;
				current_diff.value=current_this.value;
				diffset.size++;
			}
		
		current_this =current_this.next;		
		}
		diffset.head=diffset.head.next;
		return diffset;
	}

	public static SLLSet union(SLLSet[] sArray) {
		
		SLLSet unionSet = sArray[0]; 
		for (int i = 1; i < sArray.length; i++) {
			unionSet = unionSet.union(sArray[i]);
		}

		return unionSet;
	}

	@Override
	public String toString() {
		String result = "";
		SLLNode current = head;

		while (current != null) {
			result = result + current.value;

			if (current.next != null)
				result += ", ";

			current = current.next;
		}

		return result;
	}
}