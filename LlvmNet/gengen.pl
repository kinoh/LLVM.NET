use strict;


my %defined_in_class = ('ID' => 'CallingConv');
my %defined_in = (
	'CallingConv' => 'llvm/IR/CallingConv.h',
	'Intrinsic' => 'llvm/IR/Intrinsics.h');
my $base_dir = $ARGV[0] . '/';

&explore("");
&output("gen.pl", "gen.pl.template");

sub explore
{
	my $dir = $_[0];

	my $d;
	opendir $d, "$base_dir$dir" or die $!;
	while (readdir $d)
	{
		next if ($_ eq "." or $_ eq "..");
		my $p = $_;
		$p = "$dir/$p" if ($dir);
		if (-d "$base_dir$p") {
			&explore($p);
		} elsif (/\.h$/) {
			&read($p);
		}
	}
	closedir $d;
}

sub read
{
	my $path = $_[0];
	my $class = "";
	my $public = 0;
	my $brace = 0;

	open F, "$base_dir$path";
	while (<F>)
	{
		if (not $class and /^\s*class (\w+)(?:[^;]+)$/)
		{
			$class = $1;
			$public = 0;
			$defined_in{$1} = $path;
		}
		elsif (/^\s*(public|private|protected):/)
		{
			$public = ($1 eq 'public');
		}
		elsif ($class and $public and /^\s*enum (\w+)?(?!\w)[^\}]*(\};)?\s*$/)
		{
			if ($1) {
				$defined_in_class{$1} = $class;
			}
			unless ($2)
			{
				while (<F>) {
					last if (/\};/);
				}
			}
		}
		elsif (/^\};/)
		{
			$class = "";
		}
	}
	close F;
}

sub output
{
	my ($out, $template) = @_;

	open O, "> $out";
	open I, $template;

	while (<I>)
	{
		if ($_ eq "#DEF defined_in_class\n")
		{
			print O "my \%defined_in_class = (\n";
			foreach (keys %defined_in_class) {
				print O "\t'$_' => '$defined_in_class{$_}',\n";
			}
			print O "\n);\n";
		}
		elsif ($_ eq "#DEF defined_in\n")
		{
			print O "my \%defined_in = (\n";
			foreach (keys %defined_in) {
				print O "\t'$_' => '$defined_in{$_}',\n";
			}
			print O "\n);\n";
		}
		else {
			print O;
		}
	}
	close I;
	close O;
}
