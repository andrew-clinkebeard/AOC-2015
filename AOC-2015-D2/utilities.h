#pragma once

class Package {
public:
	int getTotalArea()
	{
		return getPackageArea() + smallestSideArea();
	}

	int getBowLength()
	{
		return smallestPerimeter() + getVolume();
	}
	

	int l = 0;
	int w = 0;
	int h = 0;

private:
	int getPackageArea()
	{
		return 2 * l * w + 2 * w * h + 2 * h * l;
	}

	int smallestSideArea()
	{
		int area = 0;

		int M = std::max({ l, w, h });
		
		if (M == l)
			area = w * h;
		else if (M == w)
			area = l * h;
		else if (M == h)
			area = l * w; 

		return area;
	}

	int smallestPerimeter()
	{
		int perimeter = 0;

		int M = std::max({ l, w, h });

		if (M == l)
			perimeter = 2 * w + 2 * h;
		else if (M == w)
			perimeter = 2 * l + 2 * h;
		else if (M == h)
			perimeter = 2 * l + 2 * w;

		return perimeter;
	}

	int getVolume()
	{
		return l * w * h;
	}


};
