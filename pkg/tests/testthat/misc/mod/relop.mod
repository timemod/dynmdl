% Test with relational operators
varexo x;
var y1 y2 y3 y4 y5 y6 y7;


model;
y1 = x < 2 == 0;
y2 = 0 == x < 2;
y3 = 2 < x < 1;
y4 = x < 2 >= 1;
y5 = x < 3 < x >= 1;
y6 = x < 2 != 0;
y7 = (x < 3) < (x >= 1);
end;
