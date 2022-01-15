/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author jianfeng
 */
public class UpperTriangularMatrix {
	private int n;
	private int[] array;

	public UpperTriangularMatrix(int n) {
		//default as 1
		this.n = 1;
		//if n greater than 0, then it is valid
		if (n > 0)
			this.n = n;
		//new array for matrix item
		this.array = new int[(this.n + 1) * this.n / 2];
	}

	public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException {
		int rowsNum = upTriM.getsizeofrows();
		int colsNum = upTriM.getsizeofcols();
		if (rowsNum != colsNum || upTriM.isUpperTr() == false)
			throw new IllegalArgumentException("Not an upper triangular Matrix");
		this.n = rowsNum;
		//if the size of matrix is n,
		//then array size is (n+1)n/2
		this.array = new int[(this.n + 1) * this.n / 2];
		int k = 0;
		//copy mtrix to aray
		for (int i = 0; i < this.n; i++)
			for (int j = i; j < this.n; j++)
				this.array[k++] = upTriM.getElement(i, j);
	}

	public int getDim() {

		/* write your implementation here and update return accordingly */
		return this.n;
	}

	public int getElement(int i, int j) throws IndexOutOfBoundsException {

		/* write your implementation here and update return accordingly */
		if (i < 0 || j < 0 || i >= n || j >= n)
			throw new IndexOutOfBoundsException("Invalid indexes");
		if (i > j)
			return 0;
		else
			return this.array[i * (2 * n - i + 1) / 2 + j - i];
	}

	public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException {
		if (i < 0 || j < 0 || i >= n || j >= n)
			throw new IndexOutOfBoundsException("Invalid index");
		if (i > j)
			throw new IllegalArgumentException();
		this.array[i * (2 * n - i + 1) / 2 + j - i] = x;
	}

	public Matrix fullMatrix() {

		Matrix full = new Matrix(n, n);
		int k = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				full.setElement(this.array[k++], i, j);
		return full;
	}

	public String toString() {
		String output = "";
		for (int i = 0; i < this.n; i++) {

			for (int j = 0; j < this.n; j++)
				if (i > j)
					output += "0 ";
				else
					output += this.array[i * (2 * n - i + 1) / 2 + j - i] + " ";
			//add newline for every row
			output += "\n";
		}
		return output;
	}

	public int getDet() {
		int product = 1;
		for (int i = 0; i < this.n; i++)
			product *= this.array[i * (2 * n - i + 1) / 2];
		return product;
	}

	public double[] effSolve(double[] b) throws IllegalArgumentException {

		/* fix the following and write your implementation */
		if (this.getDet() == 0)
			throw new IllegalArgumentException("The determinant of the matrix is 0");
		if (this.n != b.length)
			throw new IllegalArgumentException("The dimension of the matrix is not defined for operation");
		double[] sol = new double[this.n];
		for (int i = this.n - 1; i >= 0; i--) {
			//it is better not to change value of b
			sol[i] = b[i];
			//start from the elm index of n-1
			for (int j = this.n - 1; j > i; j--) {
				sol[i] -= sol[j] * this.array[i * (2 * n - i + 1) / 2 + j - i];
			}
			sol[i] /= this.array[i * (2 * n - i + 1) / 2];
		}
		return sol;
	}
}
