#!/usr/bin/python3
"""
This script reads stdin line by line and computes metrics.
"""


import sys
import signal

# Initialize variables
total_file_size = 0
status_code_counts =
{
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}
line_count = 0


def print_stats():
    """Prints the current statistics."""
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts.keys()):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")


def signal_handler(sig, frame):
    """Handles the keyboard interrupt signal (CTRL + C)."""
    print_stats()
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)


try:
    for line in sys.stdin:
        try:
            parts = line.split()
            if len(parts) < 7:
                continue

            status_code = parts[-2]
            file_size = parts[-1]

            if status_code in status_code_counts:
                status_code_counts[status_code] += 1

            total_file_size += int(file_size)

            line_count += 1

            if line_count % 10 == 0:
                print_stats()

        except Exception:
            continue

    print_stats()

except KeyboardInterrupt:
    print_stats()
    raise
