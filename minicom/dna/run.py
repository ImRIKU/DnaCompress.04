import sys
import os

def create_fastq(file_name):
    # Read the content of the input file
    with open(file_name, 'r') as input_file:
        content = input_file.read().replace('\n', '')

    # Prepare the content for the FASTQ file
    fastq_lines = []
    fastq_lines.append("@SEQ_ID")
    
    # Split the content into lines of at most 60 characters
    for i in range(0, len(content), 60):
        fastq_lines.append(content[i:i+60])
    
    fastq_lines.append("+")
    fastq_lines.append("!''*((((***+))%%%++)(%%%%).1***-+*''))**55CCF>>>>>>CCCCCCC65")

    # Write the content to the output FASTQ file
    output_file_name = f"{file_name}.fastq"
    with open(output_file_name, 'w') as output_file:
        output_file.write('\n'.join(fastq_lines))

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python run.py <file_name>")
        sys.exit(1)

    file_name = sys.argv[1]
    create_fastq(file_name)
    print(f"Output written to {file_name}.fastq")
