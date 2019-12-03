# Rectangles in a 2-Dimensional (R^2) Space.
## Solution by Raunak Bhagat

_**Problem**_
Given a 2-dimensional (R^2) space, S, and a set of points, P, such that each point in P is an element of the space S, design an algorithm that calculates the number of rectangles that can be formed.
For example, the following points would return a result of 6.
	.     .     .     .
	.     .     .     .
*Note:* The points do not need to be uniformly distributed, as in the example above. The following example is also a valid set of points.
	.    .   .     .       ...      .
	   .               . .
	. . .     .   . . .   .   .  .
	       .    .                   .  .

_**(My Best) Solution:** (Time-Complexity: O(n^2))_
*Before We Start:* My solution to this problem requires a solid foundation in Linear Algebra.
*Algorithm Explanation (Brief):*
I initially struggled with this problem, but as soon as I started applying the formal definition of what a rectangle is, I was able to lay the groundworks of my idea fairly quickly.
A rectangle can have multiple definitions, but the one I chose (which helped me solve this problem) was:
_A rectangle is a 2-dimensional closed polygon such that **all** internal angles are pi/2 radians._
That is all that is needed to define what a rectangle is. One does not need to specify the number of sides, the length of each side, whether or not the two opposite sides are parallel or not. If the above requirements are met, then it *has* to, by definition, be a rectangle. (I won't go into the proof of why this is true, it is kind of trivial...)

Therefore, by taking advantage of this fact, I came up with the following algorithm:
1.	Select a point, p_a, such that p_a is an element of the set P.
2.	Select antoher point, p_b, such that p_b is an element from the set P and p_a != p_b.
3.	Calculate the line vector that is formed by these two points. Let's call this line vector L_a.
4.	Calculate the subspace which is perpendicular to L_a. Since we are working in 2-dimensional space, this subspace would also be a line vector. However, in 3-dimensional space, the perpendicular subspace would be a planar subspace. In general, in an n-dimensional space, the subspace which is perpendicular to the line vector L_a has a degree of (n-1). Let's call this subspace A_p.
5.	Iterate over all the remaining points in the set P to check whether or not they exist in the perpendicular subspace, A_p.
	* Item 5a	If it's discovered that a point in the remaining set exists in the perpendicular subspace A_p, create a new user-defined object called a *Corner*.
	* Item 5b	A Corner object is defined as a having 3 points (A, B, C), such that the angle ABC will be pi/2 radians.
	* Item 5c	This *Corner* object will have 3 fields in it:
		* Item i	Edge A: defined as the one of the corner's edges.
		* Item ii	Edge B: defined as the second of the corner's edges.
		* Item iii	Base: define as the point that connects to Edge A and Edge B. The angle of the angle formed by connecting (EdgeA)-(Base)-(EdgeB) should be pi/2 radians.
	* Item 5d	After creating this corner object, place it in a HashSet, where the index of the array is determined by hashing *only the edges* and the actual element in the index is the Corner object.
		* Item i	(The reason why we hash based on only the edges, and don't take the base into account, will become apparent later on...)
		* Item ii	If the insertion into the HashSet results in a collision, then check to see if two Corner objects that are colliding have the same edges but a _**different**_ base.
		* Item iii	Making sure that the base is different if the edges match is extremely important! This guarantees to us that these two Corner objects form a square! This is also the reason we insert into the set by only hashing the edges. Corner objects that have the same edges will *definitively __have__* to hash to the same value! Thus, if two Corner objects hash to the same value, then that means either that the two Corner objects are *exactly* identical (which doesn't form a square) or the two Corner objects differ only by a base! And since Corner objects are defined such that all bases have an angle of pi/2, two Corner objects that hash to the same value but have different bases must, by definition, be a rectangle!
	* Item 5e	Create a new Shape object that consists of all the four points that constitute the rectangle. Insert it into a set of Shape objects. Let's call this set of Shape objects R. (If there exists another Shape object in the set R, then insertion into this set will fail).
6.	Repeat steps 2 through 6 for the rest of the points. Essentially, increment p_b (i.e. choose a new p_b such that (p_b_new != p_b_old) && (p_b_new != p_a).
7.	Repeat steps 1 through 7 for the rest of the points. Essentially, increment p_a (i.e. choose a new p_a such that (p_a_new != p_a_old).
8.	Return the length of the set of Shape objects, length(R). This is the answer.


One important thing to note about this algorithm is that it is extendable to consider rectangles in spaces of higher dimensions. When we found the perpendicular subspace, we were essentially finding all the matrices, M, element of R^(2x1) [a 2-by-1 matrix], such that M multiplied by the vector portion of the line vector, L_a, would result in 0. The matrix, M, in this 2-dimensional problem, would just be an element of R^(2x1) [a 2-by-1 matrix], but in n-dimensions, M would just be an element of R^(nx1) [an n-by-1 matrix]! And finding out all the different possibilities of this matrix would essentially be finding out the nullspace (a.k.a. the perpendicular space)! Therefore, the matrix would be defined such that transposing it would result in a vector that is an element of the nullspace!
Another important thing to note is that this problem can not only be extended to think of rectangle in n-dimensional space, but can also be extended to think of *pentagons, hexagons, heptagons, etc.* in n-dimensional space (although, I do admit, this specific extension would increase the difficulty of this algorithm tenfold). This is because finding the perpendicular subspace of a line vector is akin to finding the nullspace of the inner product. We are essentially asking, "What subspace, A_p, of this space, S, exists such that every element in this subspace, when inner producted with the line vector, L_a, will result in 0?". We use 0 in this case because we want the Corner object to have an angle of pi/2 radians. However, if we change the value of 0 to any real number between 0 and 1, we can define Corner objects as having any  angle we choose! This will allow us to inspect other types of polygons, such as pentagons, hexagons, heptagons, etc. in n-dimensional space!

In my opinion, the two cruxes of this algorithm were: a) finding the perpendicular space of the line vector, L_a, and b) inserting the Corner objects into a HashSet based on only their edges. I believe that O(n^2) is the most efficient algorithm that can be produced for this type of question (although I have no substancial work to prove so).
