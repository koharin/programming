CREATE OR REPLACE VIEW studentview(s_id, s_pwd, s_addr)
AS
select s_id, s_pwd, s_addr
from students;
