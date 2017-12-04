var y z;

parameters c0 c1 theta;

c0 = 1; c1 = 2; theta = 0.1;

model;
y = c0 + 2222 * c1 * z;
z = z(-1) + 0.1 * z(1) + theta;
end;
