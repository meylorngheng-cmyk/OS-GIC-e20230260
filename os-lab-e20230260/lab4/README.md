# Lab 04 - Linux I/O Redirection and Pipelines

## Objectives
- Practice Linux input/output redirection.
- Understand stdout and stderr.
- Use pipes to connect commands.
- Filter and count lines using grep, cut, and wc.
- Save and display output using tee.

## Commands Practiced

### Pipelines
grep '^ready,' data/events.csv | cut -d ',' -f 2 | wc -l

### Output Redirection (Overwrite)
>

### Output Redirection (Append)
>>

### tee
tee filename

### Redirect Standard Error
2> errors.txt

### Combine stdout and stderr
2>&1

## Results
- Ready records were counted successfully.
- Paid records count was 2.
- A pipeline with no matches returned 0 lines.
- A missing file produced an error on stderr.
- The pipeline exit status normally reflects the last command.

## Files
- ready_counts.txt
- ready_counts2.txt
- errors.txt
- combined.txt
- paid_total.txt
- evidence/
