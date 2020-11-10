# Import EEPROM Class
from ES2EEPROMUtils import ES2EEPROM

def main():
    # Create EEPROM object
    eeprom = ES2EEPROM()

    # Read EEPROM stored records
    data = eeprom.read_block(0, 84)

    # Print out EEPROM stored records
    eeprom.print_mock_scores(data)

main()
