## 数据库

#### 基本概念

DB（database）：保存了一系列有组织的数据。存储数据的仓库

DBMS（database management system）：数据库管理系统，可通过该系统创建和操作数据库。常见的数据库管理软件：MySQL、Oracle、DB2（适合处理海量数据，所以小数据体现不出优势）、SqlServer（只能安装在windows）。

SQL（Structure Query Language）：结构化查询语言：用来与数据库通信的语言。

SQL优点：1、不是某个特定数据库供应商专有的语言，几乎所有的DBMS都可支持SQL；

​                    2、简单易学             3、实现较高级的功能。

#### 数据库好处

1、可以持久化数据到本地

2、结构化查询Structure Query Language

#### 数据库特点

1、数据放在表中，表再放入数据库中；

2、一个数据库中有多个表，每个表1都有一个名字，用于标识自己。。且表明具有唯一性；

3、表具有一些特性，定义了数据在表中如何存储；

4、表由列组成，也就是**字段**。所有表都是由一个或多个列组成，每列类似于“属性”；

5、表中数据是按行存储的，类似于“对象”。

### MySQL

优点：1，开源、免费、成本低；2，性能高、移植性好；3、体积小便于安装



#### 启动与停止

管理员运行命令提示符：

```mysql
net start mysql
net stop mysql
```

#### 进入数据库

```mysql
// 1、 打开安装好的shell，输入密码即可
// 2、命令提示符
mysql -h localhost -P 3306 -u root -p   // -h 是指host主机名字   -P 为端口号    -p 密码
```

#### 常见命令

```mysql
show databases;   # 自带的数据库：mysql保存用户信息。

use test;         # use 进入数据库test
show tables;      # 显示数据库test中的表
show tables from mysql;  # 在test数据库中查看mysql库中的表信息
select database();    # 查询当前所在数据库（输出test）

create table try1(         # 创建表
   -> age int,
   -> name varchar(11));

desc try1;   # 查看表的结构
select * from try1;  -- 查找数据

insert into try1 (age,name) values(11,'lewao');

update try1 set name = "kk";   -- 更新数据


```

#### 语法规范

1、不区分大小写，但建议关键字大写、表名、列名小写。      2、每条命令用分号结束          3、可进行缩进或换行  4、注释

### SQL语言

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200826141905645.png" alt="image-20200826141905645" style="zoom:67%;" />

#### DQL（data query language）查询

##### 基础查询

```mysql
# 一、新建learn表（name，age，id）

create table learn(
name varchar(20),
age int,
ID varchar(20));
)

# 二、基础查询(select 实际上类似于打印函数，输出函数，，从select常量值即可看出其功能)

/*
	语法:select 查询列表 from 表名
    1、查询列表可以是：表中字段、常量值、表达式、函数
    2、查询的结果是一个虚拟的表格（并未存储，只是显示）
*/

# 2、查询某个字段 select “字段名” from “表名”

select age from learn;

# 3、查询多个字段

select age,ID from learn;

# 4、查询所有字段

select * from learn;

# 5、查询表达式

select age = 11 from learn;   # 输出会是一个表格，符合要求的为1，不符合的为0

# 6、查询函数

select VERSION() from learn;  # 输出安装版本号

# 7、查询常量值

select 100 from learn;   # 每一行均输出该常量值

# 8、为字段写别名，a、便于理解  b、若查询字段重名，可区分开来

select 100/2 as 结果;
SELECT NAME AS 姓名 FROM learn;

SELECT age 年龄 FROM learn;

# 注：若取别名时，别名有关键字或特殊符号#等，需用双引号包含

# 9、去重（若数据中某字段有重复的value值，通过去重可以避免重复显示）

SELECT DISTINCT NAME FROM learn;

# 10、加号的作用

/* 
mysql中加号的作用只为运算符，不能直接连接字符串
	select "100"+90 ;  若能转换字符串，则转换后相加 == 190
	select "john" + 90; 若无法转换，则将字符串转换为0，再相加 == 90
	select null + 90; 若有一个为null，则最后结果肯定为null
*/

# MYSQL中利用concat连接（注意，若拼接一方为NULL，则拼接后也为NULL）

# 案例：查询员工名和ID，并连接在一起

SELECT CONCAT(NAME,id) FROM learn;

```

##### 条件查询

```mysql

# 二、条件查询(先执行表名、在执行筛选、最后查询列表)
/*
	select
			查询列表
	from
			表名
	where
			筛选条件;
	
	分类：
		1、按条件表达式筛选 > < = <> >= <=
		2、按逻辑表达式筛选 && || ! and or not
		3、模糊查询 like     between     in      is null
*/
 # 1、按条件表达式筛选
SELECT
	NAME
FROM
	learn
WHERE
	NAME != "here"

# 2、按逻辑运算符查询
SELECT
	*
FROM
	learn
WHERE
	NAME != "here" && age >21
	
# 3、模糊查询
# 通常与通配符搭配查询  %：任意多字符，包含0个
SELECT
	*
FROM
	learn
WHERE
	NAME LIKE "%a%"   # 输出包含a的名字
# _: 占位置
SELECT
	*
FROM
	learn
WHERE
	NAME LIKE "___a_" # 输出低4个字符为a的名字

# 注：若想要找包含_的名字，故不能直接这样写，写的话会占位置，应该转义

SELECT
	*
FROM
	learn
WHERE
	NAME LIKE "%\_%" # 输出包含下划线的字符名字
	
SELECT
	*
FROM
	learn
WHERE
	NAME LIKE "_$_%" escape '$' # 指定$为转义字符，输出第二位为下划线的名字
	

/*
	1、between and包含临界值
	2、between a and b   b>=a
*/
SELECT
	*
FROM
	`employees`
WHERE
	employee_id BETWEEN 100 AND 120;

/*
	In:
	1、In列表值类型必须统一/兼容
	2、不可写通配符（通配符需与like公用，而in等价于=）
	
	查询员工工种编号是IT_PROG、AD_VP、AD_PRES中的一个员工名和工种编号
	
*/
SELECT 
	last_name,
	job_id
FROM
	employees
WHERE
	# 当查询较多时，不方便一个一个写，需要用到In
	# job_id = "IT_PROG" OR job_id = "AD_VP" OR job_id = "AD_PRES";
	job_id IN ("IT_PROG" ,"AD_VP" ,"AD_PRES")
	
/*
	is null:
	1、= 或<>不能判断null值
		
	案例：查询没有奖金的员工名和奖金率
*/
SELECT 
	`last_name`,
	`commission_pct`
FROM
	`employees`
WHERE
	# 不能直接等于 null
	# `commission_pct` = null;
	`commission_pct` IS NULL;
	
# 案例：查询有奖金的员工名和奖金率
SELECT 
	`last_name`,
	`commission_pct`
FROM
	`employees`
WHERE
	`commission_pct` IS NOT NULL;
	
/*
	安全等于<=>
		既可以判断null值也可判断普通值
	
	案例：查询没有奖金的员工名和奖金率

	
*/
SELECT 
	`last_name`,
	`commission_pct`
FROM
	`employees`
WHERE
	`commission_pct` <=> NULL;

```

##### 排序查询

```mysql
/*
	语法：
	selsect  查询列表
	from     表
	where    筛选条件
	order by 排序列表 [asc|desc]
	
	特点：
	1、asc：升序，不写默认升序
	2、desc：降序
	3、order by 一般放在最后，limit语句除外
	排序列表 支持单字段、多字段、函数、表达式、别名等
*/

# 查询员工信息，从高到低排序
SELECT 
	* 
FROM 
	employees 
ORDER BY
	salary DESC;

# 对于多字段排序:每个字段后均需加排序参数，不加默认降序。。且按字段先后优先排序
# 下面的案例中先按commission排序，相等的话再按salary排序【按多字段查询】
SELECT 
	* 
FROM 
	employees 
ORDER BY
	`commission_pct` DESC,salary DESC;   
	

# 按年薪的高低显示员工的信息【按别名排序】
# 因为年薪不存在，故需在selsec的起一个年薪

SELECT 
	* ,salary * 12 *(1+IFNULL(`commission_pct`,0)) 年薪
FROM 
	employees 
ORDER BY
	年薪 DESC;


# 按姓名长度显示员工的姓名和工资【按函数排序】
SELECT
	CONCAT(`first_name`,`last_name`) AS 姓名,
	`salary`,
	# length(姓名) as 长度  错，虽然定义了姓名为新的名字，但姓名字段并不存在于原表中
	LENGTH(CONCAT(`first_name`,`last_name`)) AS 长度
FROM
	`employees`
ORDER BY
	长度 DESC;  # 此处排序的不是原表，而是新生成的虚拟表，故可直接用别名



# 按年薪的高低显示员工的信息【按别名排序】
# 因为年薪不存在，故需在selsec的起一个年薪

SELECT 
	* ,salary * 12 *(1+IFNULL(`commission_pct`,0)) 年薪
FROM 
	employees 
ORDER BY
	年薪 DESC;


# 按姓名长度显示员工的姓名和工资【按函数排序】
SELECT
	CONCAT(`first_name`,`last_name`) AS 姓名,
	`salary`,
	# length(姓名) as 长度  错，虽然定义了姓名为新的名字，但姓名字段并不存在于原表中
	LENGTH(CONCAT(`first_name`,`last_name`)) AS 长度
FROM
	`employees`
ORDER BY
	长度 DESC;  # 此处排序的不是原表，而是新生成的虚拟表，故可直接用别名


# 选择工资不在8000到17000的员工姓名和工资，按工资降序
SELECT
	`last_name`,
	`salary`
FROM
	`employees`
WHERE
	`salary` NOT BETWEEN 8000 AND 17000
ORDER BY
	salary DESC;
	
# 查询邮箱中包含e的员工信息，并先按邮箱的字节数降序，再按部门编号升序
SELECT
	*
FROM
	`employees`
WHERE
	`email` LIKE "%e%"
ORDER BY
	LENGTH(email) DESC,
	`department_id` ASC;

```



```mysql
# 面试题:

/*
	select * from employees; 
	select * from employees where commission_pct like "%%" and last_name like "%%";
	是否一样？
	
	不一样：若判断的字段有NULL，则不一样。（模糊查询无法找出null）
	
	但若
	select * from employees where commission_pct like "%%" or last_name like "%%" or  blablabla;
	因为总归有字段不为null，故or时会一样
*/

```

##### 常见函数的

​	概念:类似于类里面的方法，将一组逻辑语句封装在方法体中，对外暴露方法名
​	好处：1、隐藏实现细节   2、提高代码复用性
​	调用：select 函数名（实参列表）【from 表】;(若用到表中元素需from)
​	
​	分类:
​	1、单行函数
​		concat、length、ifnull
​	2、分组函数/统计函数

#####  1、单行函数

###### 1、字符函数

```mysql

SELECT LENGTH("john");    # 占4个字节
SELECT LENGTH("谁111");   # 占6个字节（一个汉字三个）

SHOW VARIABLES LIKE "%char%";
# 2、拼接函数
SELECT CONCAT(`first_name`,`last_name`) FROM `employees`;

# 3、大小写变化
SELECT UPPER("lewao");
SELECT LOWER("shuayuan");

# 4、截取：索引从1开始
SELECT SUBSTR("lewao come from",3);    # 从3开始往后
SELECT SUBSTR("lewao come from",7,4);  # 截取固定长度（7开始，长度为4）

# 姓名中首字符大写，其他字符小写，然后用_拼接，显示出来
SELECT CONCAT(UPPER(SUBSTR(`last_name`,1,1)),LOWER(SUBSTR(`last_name`,2))) 
FROM `employees`;

# 5、instr(返回字串的起始索引)
SELECT INSTR("shuayuanhasaapple","yuan") AS output;  # 5

# 6、trim(去除前后某字符或字符串)
SELECT TRIM("    lewao    ") AS output;
SELECT TRIM('aa' FROM "aaaaalewaaoaaaaa");  # alewaoa

# 7、rpad lpad(用指定字符组成指定长度)
SELECT LPAD("shua",8,"yuan");   # yuanshua
SELECT RPAD("shua",8,"yuan");   # shuayuan

# 8、replace
SELECT REPLACE("shuayuan","shua","la");   # layuan
```

###### 2、数学函数

```mysql
# 1、round(四舍五入)
SELECT ROUND(1.22);    #  1
SELECT ROUND(1.222,2); #  1.22

# 2、ceil(向上取整)、floor(向下取整)
SELECT CEIL(1.22);    # 2
SELECT FLOOR(1.22);   # 1

# 3、truncate(截断),保留一位小数
SELECT TRUNCATE(1.22,1);  # 1.2

# 4、取余:a-a/b*b
SELECT MOD(-1.65,1);  # -0.65  -1.65+1.65/1*1 = -0.65
SELECT MOD(1.65,-1);  # 0.65   1.65 - 1.65/-1*-1

```

###### 3、日期函数

```mysql
# 1、now(返回当前系统日期+时间)
SELECT NOW();

# 2、curdate(返回当前日期)
SELECT CURDATE();

# 3、curtime
SELECT CURTIME();

# 4、获取指定的部分;年、月、日等
SELECT YEAR(NOW()) 年;
SELECT SECOND(NOW()) 秒；

SELECT YEAR(`hiredate`) AS 雇佣时间 FROM `employees`;

# 5、str_to_date(将日期格式的字符转化为指定格式)
SELECT STR_TO_DATE("12-12-1991","%d-%c-%Y");
# 查询员工信息
SELECT 
	* 
FROM 
	`employees`
WHERE
	`hiredate` = STR_TO_DATE("1992 4-3","%Y %c-%d");

# 6、将日期转化为字符
SELECT DATE_FORMAT(NOW(),"%Y年%c月");

# 查询有奖金的员工名和入职日期
SELECT `last_name`as员工名, DATE_FORMAT(`hiredate`,"%Y年%c月")
FROM `employees`
WHERE `commission_pct` IS NOT NULL;

```

###### 4、流程控制函数

```mysql
# 1、if函数-相当于三目运算符
SELECT IF(10<5,10,5);     # 5

SELECT `last_name`,IF(`commission_pct` IS NULL,"haha","he") FROM `employees`; 

# 2、case函数
# 使用1：switch case函数
# case 要判断的字段或表达式  when 常量1 then 要显示的值1  
#     			     when 常量2 then 值2；…… else 值n else

# 查询员工的工资，若部门号为30，则工资乘以1.1；；40则乘1.2(等值判断)
SELECT `salary`,`department_id`,
CASE `department_id`
WHEN 30 THEN `salary`*1.1   # 不能加逗号
WHEN 40 THEN `salary`*1.2
ELSE `salary`*2
END AS 工资
FROM
	`employees`;

# 查询员工工资情况，若大于2万，显示A；大于15000，显示B；大于10000，显示C
SELECT `salary`,
CASE
WHEN `salary` > 20000 THEN "A"
WHEN `salary` BETWEEN 15000 AND 20000 THEN "B"
WHEN `salary` < 15000 THEN "C"
ELSE "D"
END AS 级别
FROM
	`employees`;
```

##### 2、分组函数

###### 1、基本函数

功能：用作统计使用，又称为聚合函数或统计函数

分类：sum求和、avg求平均值、max最大值、min最小值、count计算个数

```mysql
# 1、简单使用
SELECT 
	SUM(`salary`),AVG(`salary`),MAX(`salary`),
	MIN(`salary`),COUNT(`salary`)  
FROM `employees`

# 2、参数支持哪些类型。且均忽略null值
# sum、avg一半均为数值型。
# max、min 可比较日期或字符型
SELECT MAX(`hiredate`) FROM `employees`;

# 3、可与distinct搭配,去重
SELECT SUM(DISTINCT `salary`),SUM(`salary`) FROM `employees`;

# 4、count
# 统计行数
SELECT COUNT(*) FROM `employees`;
SELECT COUNT(1) FROM `employees`; 
# 效率：
# myisam 存储引擎下，count(*)效率高
# innodb 下，二者差不多，比count（字段）高

# 5、和分组函数一同查询的字段要求是group by
# （因为单纯用字段的话，分组函数后出现的是一个元素。字段是多个元素，故一同显示无意义）

# 6、查询员工表中最大入职时间和最小入职时间的相差天数
SELECT DATEDIFF(MAX(`hiredate`),MIN(`hiredate`)) AS difference FROM `employees`;

# 7、查询部门编号为90的员工个数
SELECT COUNT(*) FROM `employees` WHERE `department_id` = 90;  # 对
SELECT COUNT(`department_id` = 90) FROM `employees`;          # 错
```

###### 2、分组查询

```mysql

# 查询每个部门的平均工资
/*
	select 分组函数，列（需出现在group by后面）
	from 表
	【where】
	group by 分组的列表
	【order by】
	
	注:查询列表必须出现在分组函数和group by后
	
	特点:
	1、分组前筛选:用到的是原始表 （下面的1-3）
	2、分组后的筛选，用到的是分组后的表（having）（下面的4-6）
	3、分组函数做条件肯定放在having中
	4、能用分组前筛选的优先使用。
	
	group by 支持单字段、多字段、表达式进行分组
		 也可进行排序操作
		 
*/

# 1、查询每个工种的最高工资
SELECT MAX(salary),job_id
FROM employees
GROUP BY job_id;

# 2、查询每个位置上的部门个数
SELECT COUNT(*),`location_id`
FROM `departments`
GROUP BY `location_id`;

# 添加筛选条件
# 3、查询邮箱中包含a字符的，每个部门的平均工资
SELECT AVG(salary),`department_id`
FROM employees
WHERE `email` LIKE "%a%"
GROUP BY department_id;

# 4、查询有奖金的每个领导手下员工的最高工资
# 有奖金为判断    每个领导手下相当于分组
SELECT MAX(salary),`manager_id`
FROM employees
WHERE commission_pct IS NOT NULL
GROUP BY manager_id;

# 添加复杂筛选条件
# 查询哪个部门员工个数大于2
# 判断：个数大于2   个数：分组
# 1、先计算部门员工个数
SELECT COUNT(*) ,department_id
FROM employees
GROUP BY department_id;
# 2、根据上述生成的虚拟表，再筛选。。此处引出having
SELECT COUNT(*) 部门个数,department_id
FROM employees
GROUP BY department_id
HAVING 部门个数>2;

# 5、查询每个工种有奖金的员工的最高工资大于12000的工种编号和最高工资
# 输出：工种编号、最高工资    分组：最高工资
SELECT MAX(salary) 最高工资,`job_id`
FROM employees
WHERE commission_pct IS NOT NULL
GROUP BY job_id
HAVING 最高工资 > 12000;

# 6、查询领导编号大于102的每个领导手下的最低工资大于5000的领导编号是哪个
# 输出：领导编号，最低工资
SELECT MIN(salary) 最低工资,manager_id
FROM employees
WHERE manager_id > 102
GROUP BY manager_id
HAVING 最低工资 > 5000;

# 按表达式或函数分组
# 按员工姓名的长度分组，查询每一组员工个数，筛选员工个数大于5的有哪些
# 输出：长度、每一组个数   
SELECT COUNT(*) 员工个数,LENGTH(`last_name`) 姓名长度
FROM employees
GROUP BY 姓名长度
HAVING 员工个数 >5;

# 按多字段分组
# 查询每个部门每个工种的员工的平均工资
SELECT AVG(salary),department_id,job_id
FROM employees
GROUP BY department_id,job_id;

# 添加排序
# 查询每个部门每个工种的员工的平均工资.并按工资高低排序
SELECT AVG(salary),department_id,job_id
FROM employees
GROUP BY department_id,job_id
ORDER BY AVG(salary) DESC;

# 查询各管理者手下员工的最低工资，且最低工资需大于6000，没有管理者的员工不计算在内
SELECT MIN(salary) 最低工资,manager_id
FROM employees
WHERE manager_id IS NOT NULL
GROUP BY manager_id
HAVING 最低工资 > 6000;

```

##### 连接查询——多表连接

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200823103515055.png" alt="image-20200823103515055" style="zoom:67%;" />

分类：

按年代分类：

​						sql92：仅支持内连接

​						sql99：支持内+外（左外和右外）+交叉连接

**按功能分类**：内连接：等值连接、非等值连接、自连接

​						外连接：左外连接、右外连接、全外连接

​						交叉连接

###### 1、sql92

```mysql
/* 
	1、等值连接
	
	1、多表连接的结果为多表的交集部分
	2、n表连接，至少需要n-1个连接条件
	3、多表顺序没有要求
	4、一半可区别名
	5、可搭配分组、排序等
*/
# 1、查询女名和对应的男名
SELECT `name`,`boyName`
FROM `boys`,`beauty`
WHERE beauty.`boyfriend_id` = boys.`id`;

# 2、查询员工名和对应的部门名
SELECT `last_name`,`department_name`
FROM `employees`,`departments`
WHERE employees.`department_id` = departments.`department_id`;

# 为表起别名:提高简洁度，区分重名（注：若取了别名，就不能再用原表名）
# 3、查询员工名、工种号(两个表都有)、工种名
SELECT `last_name`,e.`job_id`,`job_title`
FROM `employees` e,`jobs` j
WHERE e.`job_id` = j.`job_id`;

# 加筛选
# 4、有奖金的员工名、部门名
SELECT `last_name`,`department_name`,commission_pct
FROM `employees` e,`departments` d
WHERE commission_pct IS NOT NULL 
AND   e.`department_id` = d.`department_id`;

# 查询城市名中第二个字符为o的部门名和城市名
SELECT `department_name`,`city`
FROM `departments` d,`locations` l
WHERE  d.`location_id` = l.`location_id`
AND    city LIKE "_o%"

# 5、加分组
# 查询每个城市的部门个数
SELECT COUNT(*) 个数, city
FROM `departments` d,`locations` l
WHERE d.`location_id` = l.`location_id`
GROUP BY city;

# 查询出有奖金的每个部门的部门名和部门的领导编号，及该部门的最低工资
# 分组查询，多表查询
SELECT `department_name`,d.`manager_id`,MIN(salary)
FROM `departments` d,`employees` e
WHERE 	d.`department_id` = e.`department_id`
AND	commission_pct IS NOT NULL
GROUP BY d.`department_id`;

# 6、加排序
# 查询每个工种的工种名和员工个数，且按员工个数降序
# 分组查询---每个工种   
 SELECT `job_title`,COUNT(*) 员工个数
 FROM `jobs` j,`employees` e
 WHERE j.`job_id` = e.`job_id`
 GROUP BY job_title
 ORDER BY 员工个数 DESC;

# 7、三表连接
# 查询员工名、部门名及所在城市
SELECT `last_name`,`department_name`,`city`
FROM `employees` e,`departments` d,`locations` l
WHERE e.`department_id` = d.`department_id`
AND   d.`location_id` = l.`location_id`;
```

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200823131908656.png" alt="image-20200823131908656" style="zoom:67%;" />

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200823131944692.png" alt="image-20200823131944692" style="zoom:67%;" />

**自连接**：相当于等值连接，但是两次查询。例如查询员工名对应的上级领导。。。那么1、找到员工名及对应的领导名，2、再重新找表，找到对应的领导。

![image-20200823132430540](C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200823132430540.png)

```mysql
select e.employee_id , e.last_name, m.employee_id,m.last_name
from emploees.e , employees m
where e.manager_id = m.employee_id;
```

###### 2、sql99

```mysql
/*
语法：
	select 查询列表
	from 表1 别名 【连接类型】
	join 表2 别名
	on 连接条件
	【where 筛选条件】
	【group by 分组】
	【having 筛选条件】
	【order by 排序列表】
	
分类：
内连接：inner
外连接：
	左外：left【outer】
	右外：right【outer】
	全外：full【outer】
交叉连接：cross
	
*/

# 一、内连接
/*
	1、可添加排序、分组、筛选
	2、inner 可省略
	3、筛选条件放在where后面，连接条件放在on后面，提高分离性。
*/
# 等值连接
# 1、查询员工名、部门名
SELECT `last_name`,`department_name`
FROM `employees` e
INNER JOIN `departments` d
ON e.`department_id` = d.`department_id`;

# 加筛选
# 2、查询名字中包含e的员工名和工种名
SELECT `last_name`,`job_title`
FROM `employees` e
INNER JOIN `jobs` j
ON e.`job_id` = j.`job_id`
WHERE `last_name` LIKE "%e%"
OR    `job_title` LIKE "%e%";

# 加分组+筛选
# 3、查询部门个数>3的城市名,和部门个数
SELECT `city`,COUNT(*) 部门个数
FROM `locations` l
INNER JOIN `departments` d
ON l.`location_id` = d.`location_id`
GROUP BY `city`
HAVING 部门个数 > 3;

# 加排序
# 4、查询哪个部门的部门员工个数>3的部门名和员工个数，并按个数降序
# 分组：按部门分组，之后求出员工个数  再having
SELECT `department_name`,COUNT(*) 员工个数
FROM `departments` d
INNER JOIN `employees` e
ON d.`department_id` = e.`department_id`
GROUP BY d.`department_id`
HAVING 员工个数 > 3
ORDER BY 员工个数 DESC;

# 三表连接
# 5、查询员工名、部门名、工种名、并按部门名降序
SELECT `last_name`,`department_name`,`job_title`
FROM `employees` e
INNER JOIN `departments` d ON e.`department_id` = d.`department_id`
INNER JOIN `jobs` j ON j.`job_id` = e.`job_id`
ORDER BY department_name DESC;

```

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200824194020852.png" alt="image-20200824194020852" style="zoom:67%;" />

```mysql
# 自连接
# 查询员工的名字、上级的名字
SELECT e.`last_name`,m.`last_name`
FROM `employees` e
INNER JOIN `employees` m ON e.`manager_id` = m.`employee_id`
WHERE e.`last_name` LIKE "%e%";
```

```mysql
/*
	外连接
	用于查询一个表有而另外一个表没有的记录。
	例如girls表中，beauty中有boy_friend id,而boys中没有。虽然两者都有ID，但并不一样，不可用内连接
	
	特点：
	1、外连接的查询结果为主表中的所有记录：
		若从表中有和他匹配的，则显示匹配的值
		若从表中没有和他匹配的，则显示null
		外连接查询结果 = 内连接查询结果 + 主表中有而从表中没有的记录
	2、左外连接:left左边的是主表。
	   右外连接:right右边的为主表
*/

# 内连接会损失一些数据。比如没有男朋友的女数据会丢失
SELECT boyName,NAME
FROM beauty 
INNER JOIN boys bo
ON bo.`id` = b.`boyfriend_id`;

# 此时，左连接会保留没有男朋友的女数据
SELECT NAME,boyName
FROM beauty b
LEFT JOIN boys bo
ON bo.`id` = b.`boyfriend_id`;  # 选择主键，因为主键可唯一标识表中数据，且不为空

# 查询哪个部门没有员工(若用内连接，无法显示emplo——id 为NULL的)
SELECT d.*,e.`employee_id`
FROM `departments` d 
LEFT JOIN `employees` e ON d.`department_id` = e.`department_id`
WHERE e.`employee_id` IS NULL;


# 交叉连接(笛卡尔乘积)
SELECT b.*,bo.*
FROM beauty b
CROSS JOIN boys bo;

# 查询编号大于3的女神的男朋友信息，若没有，则null填充
SELECT b.*,bo.*
FROM `beauty` b 
LEFT JOIN `boys` bo ON b.`boyfriend_id` = bo.`id`
WHERE b.`id` > 3;

# 查询哪个城市没有部门
# 注意外连接的特点是，若右表中没有符合条件的，则为null。。本题查没有部门的，只需将城市外连接，若无部门，null即可
SELECT l.city,d.`department_id`
FROM `locations` l
LEFT JOIN `departments` d ON l.`location_id` = d.`location_id`
WHERE d.`department_id` IS NULL;

# 查询部门名为sal或it的员工信息
# 因为可能没有员工，故需要外连接
SELECT e.*,d.`department_name`
FROM `departments` d
LEFT JOIN `employees` e ON d.`department_id` = e.`department_id`
WHERE d.`department_name` IN ("SAL","IT");
```

##### 子查询

出现在其他语句中的select语句，称为**子查询或内查询**。

内部嵌套其他select语句的查询，称为**外查询/主查询**。

**分类：**
按子查询出现的位置：select后（仅支持标量子查询）
		    from后（支持表子查询）
		    where或having后（标量子查询或列子查询、行子查询）
		    exists后（表子查询）
安结果集的行列数不同：标量子查询（结果集只有一行一列）——单行子查询
		      列子查询（结果集只有一列多行）  ——多行子查询
		      行子查询（结果集只有一行多列）
		      表子查询（结果集常为多行多列）

###### where/having后的子查询

特点：

- 1、子查询放在小括号内
- 2、子查询放在条件的右侧
- 3、标量子查询，一般搭配着多行操作符使用  in/any/some/all

```mysql
/*
	分类：
	按子查询出现的位置：select后（仅支持标量子查询）
			    from后（支持表子查询）
			    where或having后（标量子查询或列子查询、行子查询）
			    exists后（表子查询）
	安结果集的行列数不同：
				  标量子查询（结果集只有一行一列）——单行子查询
			      列子查询（结果集只有一列多行）  ——多行子查询
			      行子查询（结果集只有一行多列）
			      表子查询（结果集常为多行多列）
	
	注：In可与not搭配，，但any，all等需要与= <>等搭配，而不能in any 应为 = any  或 不能 not all 而应为 <>all
*/

## 1、标量子查询（当行查询）

# 1、查询abel工资
SELECT  salary
FROM employees
WHERE last_name = "Abel";

# 2、查询工资大于Abel的员工
SELECT *
FROM employees
WHERE salary > (
		SELECT  salary
		FROM employees
		WHERE last_name = "Abel"
		);
		
# 3、返回job_id与141号员工相同，salary比143号员工多的员工 姓名、job_id和工资
SELECT `last_name`,`job_id`,`salary`
FROM employees
WHERE job_id = (
		SELECT job_id FROM employees WHERE employee_id = 141
		)
AND   salary > (SELECT salary FROM employees WHERE employee_id = 143);

# 4、返回公司工资最少的员工的last_name，job_id和salary
SELECT last_name,job_id,salary
FROM employees
WHERE salary = (
		SELECT MIN(salary) FROM employees);

# 5、查询最低工资大于50号部门最低工资,的部门id和其最低工资
# 首先需要求出50号部门的最低工资  然后求各部门的最低工资
SELECT `department_id`,MIN(salary) 最低工资
FROM employees
GROUP BY department_id
HAVING 最低工资 > (
		   SELECT MIN(salary) FROM employees WHERE department_id);


## 列子查询（多行查询）
# 1、返回location_id 是1400和1700的部门中的所有员工姓名
# location id 和员工在两个表中，应该根据location找到部门id，再找到员工
SELECT last_name 
FROM employees e
WHERE department_id IN (
			SELECT DISTINCT department_id FROM departments WHERE location_id IN (1400 ,1700));

# 2、返回其他部门中比job_id为‘IT_PROG’部门任一工资低的员工号、姓名、job_id、salary
SELECT `job_title`,`last_name`,`job_id`,`salary`
# 先查询制定部门的工资
SELECT DISTINCT salary FROM employees WHERE job_id = "IT_PROG";
# 再查询
SELECT last_name,employee_id,job_id,salary
FROM employees
WHERE salary < ANY(SELECT DISTINCT salary FROM employees WHERE job_id = "IT_PROG")
AND job_id <> "IT_PROG";

## 行子查询（结果集为一行多列）  不重要
# 1、查询员工编号最小且工资最高的员工信息
# 一般写法
SELECT *
FROM employees
WHERE employee_id = (SELECT MIN(employee_id) FROM employees)
AND   salary = (SELECT MAX(salary) FROM employees); 
# 行子查询  要求判断运算符一致
SELECT *
FROM employees
WHERE (employee_id ,salary) = (SELECT MIN(employee_id),MAX(salary) FROM employees);



```

###### select后的子查询

```mysql

# 1、查询每个部门的员工个数

# 连接查询
SELECT d.*,COUNT(*)
FROM `departments` d
LEFT JOIN `employees` e ON d.`department_id` = e.`department_id`
GROUP BY d.`department_id`;  # 此处d.`department_id` 与 e.不一样

#select后查询
SELECT d.*,(
	    SELECT COUNT(*) FROM employees e WHERE e.department_id = d.`department_id`
) 个数
FROM departments d;

# 2、查询员工号 = 102的部门名
SELECT (SELECT department_name FROM departments d WHERE d.department_id = e.`department_id`)
FROM employees e
WHERE e.`employee_id` = 102;
```

###### from后面

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200825154352588.png" alt="image-20200825154352588" style="zoom:67%;" />

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200825154429666.png" alt="image-20200825154429666" style="zoom:67%;" />

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200825154702125.png" alt="image-20200825154702125" style="zoom:67%;" />

###### exists后面（相关子查询）

```mysql

SELECT EXISTS(SELECT employee_id FROM employees);   # 结果为1，即有值
SELECT EXISTS(SELECT employee_id FROM employees WHERE salary = 30000);   # 结果为0，即查找不到

# 1、查询有员工的部门名

# 左外连接实现
SELECT DISTINCT `department_name`
FROM departments d
LEFT JOIN employees e ON e.`department_id` = d.`department_id`  
WHERE e.`employee_id` IS NOT NULL;

# 因为要求是有员工的部门，故直接采用内连接即可
SELECT DISTINCT `department_name`
FROM departments d
JOIN employees e ON e.`department_id` = d.`department_id`;

# exist实现
SELECT department_name 
FROM departments d
WHERE EXISTS(SELECT * FROM employees e WHERE e.`department_id` = d.`department_id`); 
# 若忽略WHERE e.`department_id` = d.`department_id`  
# 则可能出现emplo表中没有的部门，该部门并未进行判断，所以会输出，而实际上该部门无人员

# in实现(在e表中的均有员工)
SELECT department_name
FROM departments
WHERE department_id IN (SELECT department_id FROM employees);

# 2、查询没有女朋友的男信息

# exist
SELECT bo.*
FROM boys bo
WHERE NOT EXISTS(SELECT boyfriend_id FROM beauty b WHERE bo.`id` = b.`boyfriend_id`);

# in方式
SELECT bo.*
FROM boys bo
WHERE bo.`id` IN (SELECT b.`boyfriend_id` FROM beauty b);
```

###### *案例

```mysql
## 查询和Zlotkey相同部门的员工姓名和工资
SELECT `last_name`,`salary`
FROM employees
WHERE department_id = (
			SELECT department_id FROM employees WHERE last_name = "Zlotkey")
AND last_name <> "Zlotkey";

## 查询工资比公司平均值高的员工的员工号，姓名和工资
SELECT `employee_id`,`last_name`,`salary`
FROM employees
WHERE salary > (
		SELECT AVG(salary) FROM employees);
		
# 查询各部门中工资比本部门的平均工资高的员工的员工号、姓名和工资
# 第一步先计算各部门平均工资
SELECT AVG(salary) FROM employees GROUP BY department_id;

#**** 连接两个表并筛选
SELECT `employee_id`,`last_name`,`salary`
FROM employees e
INNER JOIN 
(SELECT AVG(salary) ag,department_id FROM employees GROUP BY department_id
)ag_dep
ON e.`department_id` = ag_dep.department_id
WHERE salary > ag_dep.ag;

## 查询和姓名中包含字母u的员工在相同部门的员工，的员工号和姓名

# 查询包含字母u的员工所在部门
SELECT department_id 
FROM employees
WHERE last_name LIKE "%e%";

# 查询该id下
SELECT `employee_id`,`last_name`,department_id
FROM employees
WHERE department_id IN (SELECT DISTINCT department_id 
			FROM employees
			WHERE last_name LIKE "%e%");
			

## 查询在部门location_id为1700的部门工作的员工的员工号
SELECT `employee_id`
FROM employees
WHERE department_id IN (SELECT department_id FROM departments WHERE location_id = 1700);

## 查询管理者是King的员工姓名和工资
SELECT e.last_name,e.`salary`
FROM employees e
WHERE e.`manager_id` IN (SELECT em.`employee_id` FROM employees em WHERE em.`last_name` = "K_ing");

## 查询工资最高的员工的姓名，要求first_name\last_name显示为一列，名称为姓.名
# 查询共总最高的员工姓名
SELECT CONCAT(last_name,first_name) "姓.名"  # 因为要写.,故需加双引号
FROM employees
WHERE salary = (SELECT MAX(salary) FROM employees);
# ,分组函数只能出现在select列表、having子句和group by子句中，尤其注意不能出现在where子句中
# where salary = max(salary);


```

##### 分页查询

```mysql
/*
	当要显示的数据一页显示不全，需要分页提交sql请求
	
	语法：
		select 查询列表
		【连接、分组、排序】
		limit offset,size
		
		offset：要显示条目的起始索引/偏移量(起始索引从0开始,第10页，0+10^1即可，方便)
		size： 要显示的条目个数
	
	特点：1、放在查询语句的最后
	      2、要显示的页数 page，每页条数size
	      select 查询列表 from 表 limit (page-1)*size,size
*/

## 1、查询前五条员工信息
SELECT * FROM employees LIMIT 0,5;

## 2、查询第11条-25条
SELECT * FROM employees LIMIT 10,15;

## 3、有奖金的员工信息，且工资较高的前10名
# 先将有奖金的员工进行排序，然后取前10名
SELECT * FROM employees 
WHERE commission_pct IS NOT NULL 
ORDER BY salary DESC
LIMIT 0,10;
```

##### 查询总结



#### DML(data manipulation language) 操作



#### DDL（data define language） 定义语言

***库的管理**与**表的管理**

与DML的删除等操作不一样，DDL针对表进行处理，DML则是针对数据进行操作

```mysql
# 1、库的创建
/*
	语法：
	create database 库名
*/

## 创建books库
CREATE DATABASE books;  # 不可重复建库
CREATE DATABASE IF NOT EXISTS books;

# 2、库的修改(为保证安全，不可进行修改库名)
## 更改库的字符集
ALTER DATABASE books CHARACTER SET gbk;

# 3、库的删除
DROP DATABASE books;
DROP DATABASE IF EXISTS	books;

# 二、表的管理
/*
	语法：
	create 表名(
		列名 列类型【长度】,
		列名 列类型【长度】,
		列名 列类型【长度】
	)
	
	alter table 表名 add|drop|modify|change column 列名 【列类型】
*/

## 创建表book
CREATE TABLE book(
	id INT,   # 编号
	bname VARCHAR(10),
	price DOUBLE,
	authorid INT,
	publishdate DATETIME
)

## 创建表author
CREATE TABLE author(
	id INT,
	au_name VARCHAR(20),
	nation VARCHAR(10)
);

## 表的修改

### 修改列名
ALTER TABLE book CHANGE COLUMN `pubdate1` pubdate DATETIME;

### 修改列的类型
ALTER TABLE book MODIFY COLUMN pubdate TIMESTAMP;

### 添加新列
ALTER TABLE author ADD COLUMN annual DOUBLE;

**### 删除
ALTER TABLE author DROP COLUMN annual;  # 注意，此时不需要加类型

**### 修改表名
ALTER TABLE author RENAME TO book_author;

### 表的删除
DROP TABLE IF EXISTS book_author; 

SHOW TABLES;

### 表的复制
INSERT INTO author VALUES
(1,"村上春树","jap"),
(2,"余华","CHI");

#### 仅复制表的结构
CREATE TABLE copy LIKE author;  # 无数据

#### 复制结构及数据
CREATE TABLE copy2 SELECT * FROM author;
**##### 若欲复制的表不在一个库中
CREATE TABLE copy2_d SELECT * FROM myemployees.`departments`;


#### 复制中国作者给copy3
CREATE TABLE copy3 SELECT * FROM author WHERE nation = "CHI";

**#### 仅复制部分结构(where 后加0表明没有符合条件的)
CREATE TABLE copy4 SELECT id,nation FROM author WHERE 0;
```

##### 数据类型

```mysql
/*
常见数据类型分类
	数值型:
		整型
		小数：
			定点数
			浮点数
	字符型：
		较短的文本：
			char、varchar
		较长的文本：
			text、blob（较长的二进制数据）
	日期型
*/

# 整型：tinyint 、smallint、mediumint、int/integer、bigint
#	  1          2          3          4          5

/*
	特点:
	1、若不设置有符号还是无符号，默认为有符号，若设置无符号，则添加unsigned
	2、若插入数据超出整型范围，会报错
	3、int(数字)代表的是显示最大宽度，而不是最长可输入的数字。
*/
## 如何设置有符号和无符号
CREATE TABLE tab_int(
	t1 INT
);

INSERT INTO tab_int VALUES(-1);  # 不报错，说明为有符号

### 新建一列，为无符号
ALTER TABLE tab_int ADD COLUMN t2 INT UNSIGNED;
INSERT INTO tab_int (t1,t2) VALUES(-1,-2);  # 报错，超出范围

### 新建自定义显示的列
ALTER TABLE tab_int ADD COLUMN t5 INT(5),t4 INT ZEROFILL;
INSERT INTO tab_int (t3) VALUES(111111);   # 虽然设定的为5，但超出后仍可显示6位

ALTER TABLE tab_int ADD COLUMN t4 INT ZEROFILL;
INSERT INTO tab_int (t4) VALUES(111);   # 此时显示0000000111，前面补0，直到10位

# 小数
/*
	1、浮点数
		float（M,D）
		double（M,D）
	2、定点型
		dec（M,D）
		decimal（M,D）
	
	特点：
	1、M和D均可省略，但为定点型时，M默认10.D默认0；；与此同时，double、float则根据实际情况而变
	2、定点型的精确度较高，若要求插入数据的精度较高，则考虑定点
	3、M意味着总的位数，D代表小数位数，不可超
*/

## 看看M和D的作用
CREATE TABLE tab_float(
	f1 FLOAT(5,2),
	f2 DOUBLE(5,2),
	f3 DECIMAL(5,2)
)

INSERT INTO tab_float 
VALUES(123.45,123.45,123.45);

INSERT INTO tab_float 
VALUES(123.456,123.456,123.456);  # 报错


INSERT INTO tab_float 
VALUES(123.4,123.4,123.4);  # 显示123.40

INSERT INTO tab_float 
VALUES(1223.4,1223.4,1223.4);  # 直接报错，因为小数占两位，整数占3位，超过三位报错

# 字符型
/*
	较短的文本
	char：固定长度的字符，消耗空间，效率较高，char(M)M可以省略，默认为1
	varchar：可变长度，节省空间，效率角度 ，varchar(M)M不可省略，
*/

CREATE TABLE tab_enum (
	t1 ENUM('春','夏','秋','冬')
	
);
INSERT INTO tab_enum VALUES('春');  # 不区分大小写
INSERT INTO tab_enum VALUES('刘');  # 报错，因为定义时，未给定该汉字

CREATE TABLE tab_set (
	t1 SET('春','夏','秋','冬')
	
);
INSERT INTO tab_set VALUES('春,夏');  # 不区分大小写
INSERT INTO tab_set VALUES('春,刘');  # 报错，因为定义时，未给定该汉字

# 日期型
/*
	datetime:占8个字节，不受时区影响，不受mysql版本影响，范围较大
	timestamp：占4个字节，受时区影响，受版本影响，支持范围较小
*/
CREATE TABLE tab_date(
	t1 DATETIME,
	t2 TIMESTAMP
);

INSERT INTO tab_date VALUES(NOW(),NOW());

```

##### 常见约束

限制表中数据，为了保证表中数据的准确和可靠性

```mysql
/*
	分类：
	not null：非空，用于保证该字段的值不能为空（必选项）
	default：默认约束，保证该字段值有默认值
	primary key:主键，用于保证该字段值具有唯一性，且非空
	unique：唯一约束，保证该字段值唯一，可以为空（座位号，不是很重要）
	chaeck：检查约束（mysql不支持），
	foreign key：外键。限制两个表的关系，保证该字段的值必须来自主表的关联列的值（员工表的部门编号、员工表的工种编号）
	#####  注:外键所引用的主表字段需建立索引或为主键
	创建约束的时机：
	1、创建表时
	2、修改表时
	
	约束的添加分类：
	列级约束
		外键约束无效果
	表级约束
		除了非空、默认，其他都支持
	
	create table 表名(
		字段名 字段类型 列级约束，
		字段名 字段类型，
		表级约束
	)
	
*/

# 列级约束
CREATE DATABASE student;
USE student;

CREATE TABLE stuinfo(
	id INT PRIMARY KEY,
	stuname VARCHAR(10) NOT NULL,
	gender CHAR(1) CHECK(gender = '男' OR gender = '女'), # 不支持
	seat INT UNIQUE,
	age INT DEFAULT 18,
)

DESC stuinfo;
SHOW INDEX FROM stuinfo;


# 表级约束:不支持非空和默认
CREATE TABLE stuinfo(
	id INT,
	stuname VARCHAR(10),
	gender CHAR(1), # 不支持
	seat INT,
	age INT,
	majorid INT(10),
	
	CONSTRAINT pk PRIMARY KEY(id),
	CONSTRAINT uq UNIQUE(seat),
	CONSTRAINT fk_stuinfo_major FOREIGN KEY(majorid) REFERENCES major(id)  # 外键建立失败,因为连接的字段没有索引（不是主键）
);

DROP TABLE major;
CREATE TABLE major(
	id INT(10) PRIMARY KEY,
	major_name VARCHAR(10)
);


# 通用写法
CREATE TABLE stuinfo(
	id INT PRIMARY KEY,
	stuname VARCHAR(10) NOT NULL,
	seat INT UNIQUE,
	gender CHAR(1),
	majorid INT(10),
	
	CONSTRAINT fk_major_id FOREIGN KEY(majorid) REFERENCES major(id)
)


```



##### 面：主键和唯一对比

1、二者均可保证唯一性

2、主键不允许为空，唯一性可为空

3、主键最多有一个，唯一约束可以多个

4、二者均允许组合。。

```mysql
CREATE TABLE stuinfo(
	id INT PRIMARY KEY,
	stuname VARCHAR(10) NOT NULL,
	seat INT UNIQUE,
	gender CHAR(1),
	majorid INT(10),
	

	primary key(stuname,id),# 联合主键，，要求二者均一致时，才算重合

)
```

##### 外键特点

1、要求在从表设置外键关系

2、主表的外键列的类型和主表的关联列的类型要求一致或兼容，名称无要求

3、主表的关联列必须是一个key（一般是主键/唯一）

4、插入数据时，先插入主表，再插入从表。。删除时，先删除从表，再删除主表。

##### 修改表时添加约束

```mysql
# 修改表时添加约束

/*
	添加列级约束
		alter table 表名 modify column 字段名 字段类型 新约束
	
	添加表级约束
		alter table 表名 add 约束类型(字段名);
*/
DROP TABLE stuinfo;

CREATE TABLE stuinfo(
	id INT,
	stuname VARCHAR(10),
	gender CHAR(1),
	seat INT,
	age INT
);

# 1、添加非空约束
ALTER TABLE stuinfo MODIFY COLUMN stuname VARCHAR(10) NOT NULL;
DESC stuinfo;

# 2、添加默认约束
ALTER TABLE stuinfo MODIFY COLUMN age INT DEFAULT 18;

# 3、添加主键
## 列级约束
ALTER TABLE stuinfo MODIFY COLUMN id INT PRIMARY KEY;
## 表级约束
ALTER TABLE stuinfo ADD PRIMARY KEY(id);

# 4、添加唯一
## 列级约束
ALTER TABLE stuinfo MODIFY COLUMN seat INT UNIQUE;
## 表级约束
ALTER TABLE stuinfo ADD UNIQUE(seat);

# 5、添加外键
ALTER TABLE stuinfo ADD COLUMN majorid INT;
ALTER TABLE stuinfo ADD CONSTRAINT fk_major_id FOREIGN KEY(majorid) REFERENCES major(id);  # 只可表级约束


# 删除约束时
/*
	删除列级约束
		alter table 表名 modify column 字段名 字段类型
	
	添加表级约束
		alter table 表名 drop 约束类型 相关字 【约束名】;  
	对于主键来说，只有一个字段可设立主键约束，直接删除即可
	
*/
# 1、删除非空约束
ALTER TABLE stuinfo MODIFY COLUMN stuname VARCHAR(10);

# 2、删除默认约束
ALTER TABLE stuinfo MODIFY COLUMN age INT ;

# 3、删除主键
## 列级约束
ALTER TABLE stuinfo MODIFY COLUMN id INT;  # 删除不了
## 表级约束
ALTER TABLE stuinfo DROP PRIMARY KEY;

# 4、删除唯一
## 列级约束
ALTER TABLE stuinfo MODIFY COLUMN seat ;   # 不可
## 表级约束
ALTER TABLE stuinfo DROP INDEX seat;
SHOW INDEX FROM stuinfo;

# 5、删除外键
ALTER TABLE stuinfo ADD COLUMN majorid INT;
ALTER TABLE stuinfo DROP FOREIGN KEY fk_major_id;  # 在创建外键时最好取个名字，不然会报错
SHOW INNODB STATUS;
```

##### 标识列

```mysql
/*
	标识列即自增长列
	可以不用手动的插入值，系统提供默认的序列值
	
	特点：
	1、标识列必须与key搭配（主键或唯一）
	2、一个表中只能有一个标识列
	3、标识列的类型只能是数值型
	4、可通过set auto_increment_increment = 3;设置步长，也可手动插入修改
	
*/

# 在创建表时设置标识列
CREATE TABLE tab_identity(
	id INT PRIMARY KEY AUTO_INCREMENT,
	NAME VARCHAR(10)
);

## 不需要给id赋值
INSERT INTO tab_identity (NAME)
VALUES('lewao');

INSERT INTO tab_identity 
SET NAME = 'Ayuan';


INSERT INTO tab_identity
VALUES(NULL,'here');

SHOW VARIABLES LIKE "%auto_increment%";  # 可修改步长，但只要一改，之前保存的id也会改

# 修改表时设置标识列
ALTER TABLE tab_identity MODIFY COLUMN id INT PRIMARY KEY AUTO_INCREMENT;

# 修改表时删除标识列
ALTER TABLE tab_identity MODIFY COLUMN id INT;

```

#### *TCL（transaction control language） 事务控制语言

**事务：**一个或一组sql语句组成一个执行单元，该**执行单元要么均执行，要么均不执行**。若该单元中某条sql语句执行失败或者产生错误，则整个单元会**回滚，即所有收到影响的数据将回到事务开始以前的状态**。只有当该单元中所有语句均执行成功，事务才会顺利进行。

**存储引擎**：在mysql中的数据用各种不同的技术存储在文件（内存）中。可通过show engines来查看

**分类：**innodb、myisan、memory等。innodb支持事务、其余两个不支持事务

###### 事务的属性:*（ACID）*

1、原子性（atomicity）：指事物是一个不可分割的工作单位，事务中的操作要么均发生，要么均不发生。

2、一致性（consistency）：事务必须使数据库的一个状态变换到另一个一致性状态。（转账，总价钱不变）

3、隔离性（isolation）：一个事务的执行不能被其他事务干扰，一个事务内部的操作及使用的数据对并发的其他事务是隔离的，并发执行的各个事务之间不能互相干扰。（具体得看隔离级别）

4、持久性（durability）：一个事务一旦被提交，他对数据库的改变就是永久性的，接下来其他的操作和数据库故障不应该对其有影响。

###### 创建事务

```mysql
/*
	事务的创建：
	
	隐式事务（没有明显的开启标志）：delete 、create、update
	显示事务：
		注:需提前设置自动提交功能为禁用（delete等命令默认是自动提交，即一句为一个事务）。
		步骤：
			1、开启事务
			set autocommit = 0;
			start transaction;  可选
			2、编写sql语句(select、insert、update、delete)增删改查
			3、结束事务
			commit；  # 提交事务
			roolback; # 回滚事务
			
			
*/

SHOW VARIABLES LIKE 'autocommit';   # 默认为开启的，

# 使用步骤
CREATE TABLE account(
	NAME VARCHAR(10),
	balance INT
);

INSERT INTO account 
VALUES('lewao',10000);
INSERT INTO account 
VALUES('here',5000);

# 创建事务
SET autocommit = 0;
START TRANSACTION;

UPDATE account SET balance = 5000 WHERE NAME = 'lewao';
UPDATE account SET balance = 10000 WHERE NAME = 'here';

COMMIT;  # 提交，
# rollback;  # 或者回滚

```

###### 数据库隔离级别

当同时运行多个事务时，若多个事务同时访问数据库中的相同数据时，若不采取隔离机制，会导致各种**并发问题**：

1、脏读：对于两个事务T1、T2，事务T1读取了被T2更新但未提交的字段之后，若T2回滚，那么T1读取的数据为临时且无效的，即为脏读。

2、修改丢失：T1、T2同时读取某一数据，T1修改完一个数据后、T2马上修改，导致T1修改的数据丢失

3、不可重复读：事务T1读取了一个字段，然后T2更新了该字段之后，T1又去读取该字段，两次读取不一样。

4、幻读：T1读取某一字段，T2插入了几行，T2再读时，就多了几行

可通过设置隔离级别来避免上述现象发生：

oracle支持两种隔离级别：read commit 和serialzable。oracle默认隔离级别是read commit。mysql支持四种，默认为可重复读

四种**隔离级别**

1、read uncommit读取未提交：允许事务读取未被其他事务提交的变更。脏读等都会出现

2、read commit读取已提交：只允许事务读取已被其他事务提交的变更。可避免脏读

3、repeatable read可重复读：确保事务可多次读取中读取相同的值，在该事务持续期间，禁止其他事务对该字段进行更新。可避免脏读和不可重复读，但会出现幻读。

4、serializable串行化：确保事务可以从一个表中读取相同的行，在事务持续期间，禁止其他事务对该表执行插入、更新和删除操作。所有并发问题均可解决，但性能低下。

```mysql
 select @@tx_isolation;   # 查看默认隔离级别
 set session transaction isolation level read uncommitted# 修改隔离级别
 
 # savepoint的使用
 set autocommit = 0;
 start transaction;
 
 delete from account where id = 15;
 savepoint a;   # 设置保存点
 delete from account where id = 10;
 rollback to a;  # 回滚到保存点
```

##### 视图

**定义**：一种虚拟存在的表，行和列的数据来自视图的查询中使用的表，并且是在使用视图时动态生成的，只**保存了sql逻辑，不保存查询结果**。（像是分组后的表，筛选时只能having，因为是虚拟表，，视图相当于把虚拟表又保存了一下）

应用场景：1、多个地方用到了同样的查询结果；2、该查询结果使用的sql语句较复杂。

```mysql
/*
	一、创建视图
	语法：create view 视图名
	      as 
	      查询语句
	      
	好处：
	      1、重用sql语句
	      2、简化复杂的sql语句操作，不必知道其查询细节
	      3、保护数据、提高安全性
	
	视图和表的区别:
	      1、创建时create view;create table
	      2、视图为虚拟表，不占内存，只保存可sql逻辑；表占内存
	      3、增删改查都可用，但有要求；均可增删改
*/
# 查询名字中包含a字符的员工名、部门名和工种信息
CREATE VIEW myv1
AS
SELECT `last_name`,`department_name`,`job_title`
FROM employees e 
INNER JOIN departments d ON e.department_id = d.department_id
INNER JOIN jobs j ON j.job_id = e.job_id;

SELECT * FROM myv1 WHERE Last_name LIKE "%a%";

# 平均工资最低的部门信息
CREATE VIEW myv2 AS
SELECT AVG(salary) AS av,d.* FROM employees e
INNER JOIN departments d ON e.`department_id` = d.`department_id`
GROUP BY e.department_id;

SELECT * FROM myv2 WHERE av = (SELECT MIN(av) FROM myv2); 

/*
	视图的修改
	
	方式1：
		create or replace view myv3
	
	方式2：
		alter view 视图名 as (select * from XXXX)
*/

/*
	视图的删除
	drop view 视图名，视图名
*/

/*
	查看视图
		desc 视图名
	or	
		show create view 视图名
 
*/

# 创建视图emp_v1,要求查询电话号码以“011”开头的员工姓名和工资、邮箱
CREATE VIEW emp_v1 AS
SELECT last_name,Salary,email
FROM employees 
WHERE phone_number LIKE '011%';

# 创建视图emp_v2，要求查询部门的最高工资高于12000的部门信息
CREATE OR REPLACE VIEW emp_v2 AS
SELECT d.*,MAX(Salary) max_sa
FROM employees e 
INNER JOIN departments d ON e.department_id = d.department_id
GROUP BY e.department_id;

SELECT * FROM emp_v2 WHERE max_sa > 12000;

/*
	视图的更新（增删改查）：在视图中操作后，原始表也会被相应的操作
*/
SELECT * FROM myv1;

# 增
INSERT INTO myv1 (last_name)VALUES('zhangfei');  # 正确
INSERT INTO myv1 (last_name,department_name)VALUES('zhangfei','ss'); # 错误，不能同时更改多个子表的数据 

# 1、包含分组函数、distinct、group by、having、union等语句不可视图更新
CREATE OR REPLACE VIEW tryv1 AS
SELECT MAX(salary) avs FROM employees 
GROUP BY department_id;
SELECT * FROM tryv1;
INSERT INTO tryv2 VALUES(100);   # 不可插入
# 2、常量视图也不可更新
CREATE OR REPLACE VIEW tryv2 AS
SELECT 'JOHN' NAME;

SELECT * FROM tryv2;
UPDATE tryv2 SET NAME = 'lee';   # 错误提示：不可更新

# 3、select中包含子查询也不可更新视图
CREATE OR REPLACE VIEW tryv3 AS
SELECT department_id,(SELECT MAX(salary) FROM employees) 最高工资 FROM employees;
SELECT * FROM tryv3;
UPDATE tryv3 SET 最高工资 = 10000;  # 报错、不可更新

# 4、用到join不可更新视图，见增的案例

# 5、创建时from一个不能更新的视图
CREATE OR REPLACE VIEW tryv4 AS
SELECT * FROM tryv3;

SELECT * FROM tryv4;
UPDATE tryv4 SET 最高工资 = 1000；   # 报错，不可更新来自视图的视图

# 6、where子句的子查询引入了from子句中的表
```

### *存储过程和函数

##### 变量

变量：系统变量（全局/会话）、自定义变量（用户变量、局部变量）。

用户变量局部变量**区别**：1、用：针对于当前的会话，定义和使用可在会话中的任何位置，必须加@符号，不用限定类型

​											2、局：针对当前beginend，定义和使用必须在beginend的第一句，常不加@符号，加类型

```mysql
/*
系统变量
	由系统提供，不是用户定义、属于服务器层面
	
	使用的语法：
		1、查看所有的系统变量：show global|【session】variables
		2、查看满足条件的部分：show global|【session】variables like '%char%'
		3、查看指定的        : select @@global|【session】.系统变量名
		
	为变量赋值：
		1、set global|【session】 系统变量名 = 值
		2、set @@global|【session】.系统变量名=值
		
	全局变量（针对所有连接）：
		作用域：服务器每次启动将为所有的全局变量赋初始值，修改时针对所有的连接有效，但不能卡跨重启
	会话变量（针对当前连接）:
		
*/
# 全局变量
## 查看所有全局变量
SHOW GLOBAL VARIABLES;

## 查看部分全局
SHOW GLOBAL VARIABLES LIKE "%char%";

## 查看指定全局变量
SELECT @@global.autocommit;

## 为某个指定的全局变量赋值
SET @@global.autocommit = 1;   # 若重新打开一个链接，则修改全局变量仍会存在；若重启，则不会存在

# 会话变量
## 查看所有会话变量
SHOW VARIABLES;
## 查看部分会话
SHOW SESSION VARIABLES LIKE "%char%";
## 查看指定会话变量
SELECT @@session.autocommit;
## 为某个指定的会话变量赋值
SET @@session.autocommit = 0;

/*
自定义变量
	声明、赋值、使用（查看、比较、运算）
*/
/*
	
	用户变量：
		作用域：针对当前会话有效
	声明并初始化：
		1、SET @用户变量名 = 值;
		2、set @用户变量名 ： 值;
		3、select @用户变量名 ：= 值:
	赋值并更新变量值
		1、SET @用户变量名 = 值;
		   set @用户变量名 ： 值;
		   select @用户变量名 ：= 值:
		2、select 字段 into @变量名 from 表
	查看：
		select @用户变量名
*/

SET @name = 'lewao';
SELECT @name;
SET @name = 'shua';

SELECT COUNT(*) INTO @name FROM employees;
/*
	局部变量：
		作用域：只在局部有效（定义他的begin end中，且在beginend的第一句话）
	
	声明：
		1、declare 变量名 类型
		2、declare 变量名 类型 default 值
	赋值：
		1、SET 局部变量名 = 值;
		   set 局部变量名 ： 值;
		   select @局部变量名 ：= 值:
		2、select 字段 into 变量名 from 表
	使用：
		select 局部变量名

*/

# 声明两个变量并赋初始值，求和,并打印
## 用户变量
SET @num1 = 1;
SET @num2 = 2;
SELECT @num1+@num2;

# 以下代码暂时报错，后续会修改
BEGIN
DECLARE NAME VARCHAR(10) DEFAULT 'lewao';
SELECT NAME;
END
```

##### 存储过程和函数

###### 存储过程

```mysql
/*
存储过程和函数
	类似于java中的方法
	
	好处：1、提高复用性 2、简化操作 3、减少了编译次数及与服务器连接次数，提高效率
*/
/*
	存储过程:
		一组预先编译好的sql语句集合，可理解成批处理语句
	
	语法：
		create procedure 存储过程名（参数列表）
		begin
			存储过程体（一组合法的sql语句）
		end
		
	注意：
		1、参数列表包含三部分：参数模式、参数名、参数类型
			参数模式：in（该参数可作为输入，该方法需调用方法传入值）
				  out（该参数作为返回值）
				  inout（该参数既需要输入，也需要返回值）
		2、若存储过程只有一句，begin end可省略
		3、存储过程体中每条结尾必须加;结尾。。。存储过程结尾使用delimiter重新设置（delimeter $）
		
	调用语法：
		call 存储过程名（实参列表）
*/

# 空参列表
## 插入admin中3条数据(不可直接在yog中运行，因为其不支持结束标记语法)
DELIMITER $
CREATE PROCEDURE insertdata()
BEGIN
	INSERT INTO admin SET username = 'lewao',PASSWORD = '111';
	INSERT INTO admin SET username = 'lewa',PASSWORD = '112';	
	INSERT INTO admin SET username = 'le',PASSWORD = '1';
END$

CALL insertdata()$  # 调用过程

# 创建带in模式参数的存储过程
## 根据女神名，查询对应的男神信息
CREATE PROCEDURE selectname(IN girlname VARCHAR(10))
BEGIN
	SELECT bo.* FROM beauty b 
	LEFT JOIN boys bo ON bo.id = b.`boyfriend_id`
	WHERE b.name = girlname;  
END
CALL selectname('小昭')$   # 若报字符集错误的信息，则设置字符集
SET NAMES gbk$

## 登陆时需要传入两个输入参数,判断是否登陆成功
CREATE PROCEDURE loginin(IN usename VARCHAR(10),IN pass VARCHAR(10))
BEGIN
	DECLARE res INT DEFAULT 0;
	SELECT COUNT(*) INTO res
	FROM admin
	WHERE usename = username
	AND pass = PASSWORD;
	
	SELECT IF(res>0,'成功','失败');
	
END$

# 创建带out模式的存储过程
## 根据女神名，返回对应男神名
CREATE PROCEDURE selectn(IN girlname VARCHAR(10),OUT boyna VARCHAR(10))
BEGIN
	SELECT bo.`boyName` INTO boyna
	FROM beauty b 
	LEFT JOIN boys bo ON b.`boyfriend_id` = bo.id
	WHERE b.name = girlname;
END

CALL selectn('小昭',@boname)$
CREATE PROCEDURE returnn(IN girlname VARCHAR(10),OUT boyn VARCHAR(10),OUT boycp VARCHAR(10))
BEGIN
	SELECT bo.`boyName`,bo.`userCP`INTO boyn,boycp
	FROM beauty b
	LEFT JOIN boys bo ON b.`boyfriend_id` = bo.id
	WHERE b.name = girlname;
END$

CALL returnn('小昭',@bname,@bcp)$
SELECT @bname,@bcp$


# INOUT模式
# 传入a、b，并将a、b翻倍返回
CREATE PROCEDURE dounum(INOUT num1 INT,INOUT num2 INT)
BEGIN
	SET num1 = num1 * 2;
	SET num2 = num2 * 2; 
END$

SET @num1 := 2$
SET @num2 := 3$
CALL dounum(@num1,@num2)$
SELECT @num1,@num2$


# 案例1:创建存储过程实现传入用户名和密码，插入到admin中
CREATE PROCEDURE insertadmin(IN uname VARCHAR(10),IN passw VARCHAR(10))
BEGIN
	INSERT INTO admin (username,PASSWORD)
	VALUES(uname,passw);
END$

CALL insertadmin('lewao','la')$

# 注意，定义变量的大小应该大于原表中的大小，若把电话varchar定义小了，则输出null
# 案例2：创建存储过程或函数实现传入女生编号，返回女神名称和电话
CREATE PROCEDURE returnsome(IN girl_id INT,OUT gi_name VARCHAR(10),OUT girl_phone VARCHAR(11))
BEGIN
	SELECT `name`,`phone` INTO gi_name,girl_phone FROM beauty WHERE id = girl_id;
END$

CALL returnsome(9,@gi_name,@girl_phone)$
SELECT @gi_name,@girl_phone$

# 案例3：创建存储过程或函数实现传入两个女生生日、返回大小
CREATE PROCEDURE comp(IN date1 DATETIME,IN date2 DATETIME,OUT res INT)
BEGIN
	SELECT DATEDIFF(date1,date2) INTO res;
END$
CALL comp('1994-1-1',NOW(),@res)$
SELECT @res$

/*
	删除；drop procedure 过程名
	查看结构：
		desc 只能查看表或视图
		show create procedure 过程名
	
*/

# 案例4：创建存储过程或函数实现传入一个日期，格式化成xx年xx月xx日并返回
CREATE PROCEDURE datetostr(IN mydate DATETIME ,OUT str_date VARCHAR(12))
BEGIN
	SELECT DATE_FORMAT(mydate,'%y年%m月%d日') INTO str_date;
END$

CALL datetostr('1994-2-1',@str_date)$
SELECT @str_date$

# 案例5：创建存储过程或函数实现传入女神名称，返回：女神 and 男神 格式的字符串
CREATE PROCEDURE comb(IN girl_name VARCHAR(10),OUT comb_name VARCHAR(20))
BEGIN
	SELECT CONCAT(b.name,' and ',IFNULL(bo.`boyName`,'null')) INTO comb_name 
	FROM beauty b LEFT JOIN boys bo ON b.`boyfriend_id` = bo.id
	WHERE b.name = girl_name;
END$
CALL comb('柳岩',@comb_name)$
SELECT @comb_name$

# 案例6：创建存储过程或函数，根据传入的条目数和起始索引，查询beauty表的记录
CREATE PROCEDURE selec(IN nums INT,IN index_f INT)
BEGIN
	SELECT * FROM beauty LIMIT index_f,nums;
END$
CALL selec(3,5)$

```

###### 函数

```mysql
/*
	存储过程和函数的区别在于，函数有且只有1个返回。
	存储过程适合做批量的插入或更新；函数通常是得到处理函数后的一个结果
	语法:
		create function 函数名(参数列表) returns 返回类型
		begin
			函数体
		end
		
	参数列表：函数名 参数类型
	
	函数体必有return语句，否则会报错
	return可以不妨在最后，但无意义
	
	当函数体只有一句话，可省略begin end
	
	调用语法 select 函数名(参数列表)
*/
# 无参有返回的
# 案例1、返回公司的员工个数
DELIMITER $
CREATE FUNCTION cnt() RETURNS INT
BEGIN
	DECLARE res INT DEFAULT 0;
	SELECT COUNT(*) INTO res FROM employees;
	RETURN res;
END$

SELECT cnt()$

# 有参返回
# 案例1：根据员工名，返回其工资
CREATE FUNCTION myfunc2(e_name VARCHAR(12)) RETURNS INT
BEGIN
	DECLARE res INT DEFAULT 0;
	SELECT salary INTO res
	FROM employees
	WHERE last_name = e_name;
	RETURN res;
END$

# 根据部门名，返回该部门的平均工资
CREATE FUNCTION myfunc3(d_name VARCHAR(10)) RETURNS INT
BEGIN
	#set @res = 0;
	SELECT AVG(salary) INTO @res 
	FROM employees e
	LEFT JOIN departments d ON e.`department_id` = d.`department_id`
	
	WHERE d.department_name = d_name;
	RETURN @res;
END$

SELECT myfunc3('Adm')$

/*
	查看函数：show create function 函数名
	删除：drop function 函数名
*/
```

### 流程控制结构

#### *分支结构（if与case多重区别）

```mysql
/*
	顺序结构：程序从上往下依次执行
	分支结构：程序从两条或多条路径中选择一条去执行
	循环结构:在满足某条件的情况下，重复执行一段代码
	
*/

/*
	分支结构
		if(表达式1，表达式2，表达式3)
	执行顺序，先1，1成立则2，不成立则3
*/

/*
	case
	
	1、等值判断
			case 变量|表达式|字段
			when 判断的值 then 返回的值1或语句1
			when 判断的值 then 返回的值2或语句2
			……
			else 要返回的值n或语句n(若为语句，则需加;)
			end case;
	
	2、类似于多重if，范围判断
			case
			when 判断条件1 when 返回的值1|语句1
			when 判断条件2 when 返回的值2|语句2
			……
			else 返回的值n|语句n
			end case;
	
	特点：
		1、既可以作为表达式，嵌套在别的语句中使用，也可独立语句使用
		2、若when中值满足条件，则执行对应的then，然后结束
		3、else可省略，若else省略且when均不满足，则返回null
*/

# 案例1：创建函数，根据传入的成绩，来显示等级，若90-100则A，80-90B
DELIMITER $
CREATE FUNCTION myfunc4(scor INT) RETURNS CHAR(1)
BEGIN
	DECLARE res CHAR(1);
	CASE
	WHEN scor<100 AND scor >90 THEN SET res = 'A';
	WHEN scor<90 AND scor >80 THEN SET res = 'B';
	WHEN scor<80 AND scor >70 THEN SET res = 'C';
	ELSE SET res = 'D';
	END CASE;
	RETURN res;
END$

/*
	if实现多重分支
	
	if 条件1 then 语句1;
	elseif 条件2 then 语句2;
	……
	else 语句n;
	end if;
	
	特点：只能用在beginend中
*/
CREATE FUNCTION myfunc5(scor INT) RETURNS CHAR(1)
BEGIN
	DECLARE res CHAR(1);
	
	IF scor<100 AND scor >90 THEN SET res = 'A';
	ELSEIF scor<90 AND scor >80 THEN SET res = 'B';
	ELSEIF scor<80 AND scor >70 THEN SET res = 'C';
	ELSE SET res = 'D';
	END IF;
	RETURN res;
END$
```

#### 循环结构——只能在beginend中

```mysql
/*
	分类：
		while、loop、repeat
		
	循环控制：
		iterate  类似于continue，结束本次循环，继续下一次
		leave    类似于break，结束当前所在循环
		
*/

/*
	【标签:】while 循环条件 do
			循环体;
	 end while【标签】;
	 
	 利用循环控制的时候才需要加标签
*/

/*
	【标签:】loop
		循环体;
	end loop 【标签】
	
	# 特点：模拟简单死循环，利用循环控制
*/

/*
	【标签：】repeat
		循环体;
	until 结束循环的条件
	end repeat 【标签】;
*/

 # 案例1 实现简单的不加控制结构的循环
 DELIMITER $
 CREATE PROCEDURE myp1(IN cnt INT)
 BEGIN
	DECLARE i INT DEFAULT 1;
	WHILE i < 20 DO
		INSERT INTO boys (boyname,userCP) VALUES(CONCAT('lewao',i),i);
		SET i = i+1;

	END WHILE;
 END$
 
 # 案例2 加循环控制，就需要加标签
 CREATE PROCEDURE myp2(IN cnt INT)
 BEGIN
	DECLARE i INT DEFAULT 1;
	a:WHILE i < 20 DO
		INSERT INTO boys (boyname,userCP) VALUES(CONCAT('lewao',i),i);
		IF i>20 THEN LEAVE a;
		END IF;
		SET i = i+1;
	END WHILE a;
 END$

```

<img src="C:\Users\a\AppData\Roaming\Typora\typora-user-images\image-20200831184937731.png" alt="image-20200831184937731" style="zoom:67%;" />