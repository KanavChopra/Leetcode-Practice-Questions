# Write your MySQL query statement below


select
    student_id,
    student_name,
    subject_name,
    count(e.subject_name) as 'attended_exams'
from
    students
    cross join subjects
    left join examinations e using(student_id, subject_name)
group by student_id, subject_name
order by student_id, subject_name;