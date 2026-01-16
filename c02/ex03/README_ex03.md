Exercise 03 — BSP (summary, pseudocode, and explanation)

Goal
- Implement a `Point` class (immutable coordinates using `Fixed`) and a function `bsp(a,b,c,point)` that returns true iff `point` is strictly inside the triangle defined by `a,b,c`.
- If `point` lies on a vertex or an edge, `bsp` must return false.

What the exercise asks
- Produce a `Point` class in Orthodox Canonical Form with `Fixed const x` and `Fixed const y` members.
- Implement `bsp(Point a, Point b, Point c, Point point)` using `Fixed` arithmetic only.
- Ensure correctness for inside, edge, vertex, and outside cases.

Approach / Key idea
- Use the 2D cross product sign test: for a triangle (a,b,c) and a point p, compute the signed area (cross product) of vectors for each triangle edge with p:
  - s1 = cross(a, b, p)
  - s2 = cross(b, c, p)
  - s3 = cross(c, a, p)
- p is strictly inside iff all s1, s2, s3 have the same sign (all positive or all negative).
- If any si == 0, p lies on an edge (or vertex) — return false per specification.

Helper: cross(p1, p2, p3)
- Computes cross product of vectors (p2 - p1) x (p3 - p1):
  - dx1 = p2.x - p1.x
  - dy1 = p2.y - p1.y
  - dx2 = p3.x - p1.x
  - dy2 = p3.y - p1.y
  - return dx1 * dy2 - dy1 * dx2
- Use `Fixed` operations; do not convert to float/double for the decision.

Pseudocode

Point class
- Members:
  - Fixed const x
  - Fixed const y
- Constructors:
  - Point() -> x=0, y=0
  - Point(float x_, float y_) -> init from floats
  - copy, assignment, destructor
- Accessors:
  - Fixed getX() const
  - Fixed getY() const

cross(p1, p2, p3)
- dx1 = p2.getX() - p1.getX()
- dy1 = p2.getY() - p1.getY()
- dx2 = p3.getX() - p1.getX()
- dy2 = p3.getY() - p1.getY()
- return dx1 * dy2 - dy1 * dx2

bsp(a, b, c, point)
- s1 = cross(a, b, point)
- s2 = cross(b, c, point)
- s3 = cross(c, a, point)
- if s1 == 0 or s2 == 0 or s3 == 0: return false  // on edge or vertex
- hasNeg = (s1 < 0) or (s2 < 0) or (s3 < 0)
- hasPos = (s1 > 0) or (s2 > 0) or (s3 > 0)
- return not (hasNeg and hasPos)

Why this works (brief)
- The sign of the cross product indicates which side of a directed edge a point lies on.
- For a convex polygon (triangle) a point is inside iff it lies on the same side of every directed edge.
- Checking all three cross signs enforces that `point` is strictly inside; equality to zero detects collinearity (edge/vertex).

Edge cases and notes
- Collinear / on-edge: si == 0 -> must return false.
- Degenerate triangle (collinear a,b,c): behavior is not specified by the subject; you can treat it as no interior — `bsp` should return false for all points.
- Use `Fixed` comparisons for equality and sign checks to avoid floating-point errors.

Complexity
- O(1) time per call, constant extra space.

Recommended tests
- Inside point -> returns true.
- Point equal to a vertex -> returns false.
- Point on an edge -> returns false.
- Point outside -> returns false.

How to create a PDF locally from this file (optional)
- If you have `pandoc` installed, run:

```powershell
cd c:\Users\user\Desktop\cpp\c02\ex03
pandoc README_ex03.md -o ex03_pseudocode.pdf
```

- Or open the Markdown in any editor and export/print to PDF.

If you want, I can now:
- produce a one-page PDF file here (if you authorize a generated PDF), or
- produce a minimal C++ skeleton that follows this pseudocode (but you said you prefer pseudocode).

