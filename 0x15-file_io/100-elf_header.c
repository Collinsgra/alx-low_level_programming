#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void printMagic(unsigned char *e_ident);
void printClass(unsigned char *e_ident);
void printData(unsigned char *e_ident);
void printVersion(unsigned char *e_ident);
void printAbi(unsigned char *e_ident);
void print_OSABI_(unsigned char *e_ident);
void printType_(unsigned int e_type, unsigned char *e_ident);
void printEntrypoint(unsigned long int e_entry, unsigned char *e_ident);
void closeELF(int elf);

/**
 * check_elf - Checks ELF file.
 * @e_ident: counter magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int noder;

	for (noder = 0; noder < 4; noder++)
	{
		if (e_ident[noder] != 127 &&
			e_ident[noder] != 'E' &&
			e_ident[noder] != 'L' &&
			e_ident[noder] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Its not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagic - magic numbers
 * @e_ident: counts magic numbers.
 *
 * Description: numbers that are magic_separated by spaces.
 */
void printMagic(unsigned char *e_ident)
{
	int noder;

	printf("  Magic:   ");

	for (noder = 0; noder < EI_NIDENT; noder++)
	{
		printf("%02x", e_ident[noder]);

		if (noder == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printClass - ELF headers cprint
 * @e_ident: a ptr to elf header
 */
void printClass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printData - Prints elf data
 * @e_ident: ptr
 */
void printData(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printVersion - version print of elf data
 * @e_ident: elf version cointainer
 */
void printVersion(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		   e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_OSABI_ - OS/ABI ,ELF header.
 * @e_ident: Elf version
 */
void print_OSABI_(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printAbi - Prints the Abi
 * @e_ident: ptr to Elf Abi version.
 */
void printAbi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * printType_ - type of elf hd
 * @e_type: ELF type.
 * @e_ident: array ptr containing the ELF class.
 */
void printType_(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * printEntrypoint - ..
 * @e_entry: address
 * @e_ident: A ptr containing class elf
 */
void printEntrypoint(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * closeELF - Close ELF
 * @elf: elf file description
 *
 * Description: cannot close exit 98 - exit code 98.
 */
void closeELF(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);

		exit(98);
	}
}

/**
 * main - Displays the all the information in elf file
 * @argc: The number of arguments supplied to the program.
 * @argv: arguments
 *
 * Return: 0 on success.
 *
 * Description: if not an ELF File exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeELF(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		closeELF(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	printMagic(header->e_ident);
	printClass(header->e_ident);
	printData(header->e_ident);
	printVersion(header->e_ident);
	print_OSABI_(header->e_ident);
	printAbi(header->e_ident);
	printType_(header->e_type, header->e_ident);
	printEntrypoint(header->e_entry, header->e_ident);

	free(header);
	closeELF(o);
	return (0);
}
