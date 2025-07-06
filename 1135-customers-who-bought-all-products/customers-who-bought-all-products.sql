select customer_id
from Customer
Group by customer_id
Having count(distinct product_key)=(select count(*) from Product)