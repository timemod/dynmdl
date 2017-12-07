var y z;
varexo x;

parameters c0 c1 theta;

c0 = 1; c1 = 2; theta = 0.1;

model;
y = c0 + 2222 * 2 * z + x;
z = z(-1) + 0.1 * z(1) + theta + x(-1);
end;
