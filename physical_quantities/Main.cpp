#include "Classes.h"


pair<double, string> mult_two_different(double first, double second, string first_l, string second_l) {
	if (strcmp(first_l.c_str(), "kg") == 0 && strcmp(second_l.c_str(), "mps") == 0 ||
		strcmp(first_l.c_str(), "mps") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<double, string>(first * second, "kgmps");
	}
	else if (strcmp(first_l.c_str(), "kg") == 0 && strcmp(second_l.c_str(), "mpss") == 0 ||
		strcmp(first_l.c_str(), "mpss") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<double, string>(first * second, "N");
	}
	else if (strcmp(first_l.c_str(), "kgmps") == 0 && strcmp(second_l.c_str(), "mps") == 0 ||
		strcmp(first_l.c_str(), "mps") == 0 && strcmp(second_l.c_str(), "kgmps") == 0) {
		return pair<double, string>(first * second / 2, "J");
	}
	else if (strcmp(first_l.c_str(), "kgmps") == 0 && strcmp(second_l.c_str(), "mps") == 0 ||
		strcmp(first_l.c_str(), "mps") == 0 && strcmp(second_l.c_str(), "kgmps") == 0) {
		return pair<double, string>(first * second / 2, "J");
	}
	// добавить все оствашиес€ операции умножени€ по шаблону
	throw invalid_argument("No such literal as result for multiplying " + first_l + " and " + second_l + " exist\n");
}

pair<double, string> divide_two_different(double first, double second, string first_l, string second_l) {
	if (strcmp(first_l.c_str(), second_l.c_str()) == 0) {
		return pair<double, string>(first / second, "");
	}
	else if (strcmp(first_l.c_str(), "kgmps") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<double, string>(first / second, "mps");
	}
	else if (strcmp(first_l.c_str(), "kgmps") == 0 && strcmp(second_l.c_str(), "mps") == 0) {
		return pair<double, string>(first / second, "kg");
	}
	else if (strcmp(first_l.c_str(), "N") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<double, string>(first / second, "mpss");
	}
	else if (strcmp(first_l.c_str(), "N") == 0 && strcmp(second_l.c_str(), "mpss") == 0) {
		return pair<double, string>(first / second, "kg");
	}
	else if (strcmp(first_l.c_str(), "J") == 0 && strcmp(second_l.c_str(), "mps") == 0) {
		return pair<double, string>(2* first / second, "kgmps");
	}
	else if (strcmp(first_l.c_str(), "J") == 0 && strcmp(second_l.c_str(), "kgmps") == 0) {
		return pair<double, string>(2 * first / second, "mps");
	}
	// добавить все оствашиес€ операции делени€ по шаблону
	throw invalid_argument("No such literal as result for multiplying " + first_l + " and " + second_l + " exist\n");
}


pair<double, string> simple_calculate(string simple_operation) {

	regex sum("\\+");
	regex subtract("\\-");
	regex multiply("\\*");
	regex divide("[\\\\/]");

	regex literals("[A-Za-z]+");
	regex nums("[0-9]*[,.]?[0-9]+");
	regex literal_before_operator("[A-Za-z]+[\\\/]");

	string final_literal;
	double result = 0.0;

	auto literals_begin = sregex_iterator(simple_operation.begin(), simple_operation.end(), literals);
	auto literals_end = sregex_iterator();

	int count = distance(literals_begin, literals_end);

	auto nums_begin = sregex_iterator(simple_operation.begin(), simple_operation.end(), nums);
	auto nums_end = sregex_iterator();

	if (distance(nums_begin, nums_end) != 2) {
		//ошибка, чисел должно быть двa
		throw invalid_argument("There should be two numbers");
	}

	double first_num = stod((*nums_begin).str().c_str());
	double second_num = stod((*(++nums_begin)).str().c_str());

	if (regex_search(simple_operation, sum)) {
		if (count == 0) {
			return pair<double, string>(first_num + second_num, "");
		}
		else if (count == 2) {
			string first = (*literals_begin).str();
			string second = (*(++literals_begin)).str();
			if (strcmp(first.c_str(), second.c_str())) {
				throw invalid_argument("Invalid sum operation: trying to sum two different values, differences in literals: " + first + " and " + second + "\n");
			}
			else {
				final_literal = (*literals_begin).str();
				return pair<double, string>(first_num + second_num, final_literal);
			}
		}
		else {
			throw invalid_argument("Invalid sum operation: trying to sum two different values, only one literal\n");
		}
	}
	else if (regex_search(simple_operation, subtract)) {
		if (count == 0) {
			return pair<double, string>(first_num - second_num, "");
		}
		else if (count == 2) {
			string first = (*literals_begin).str();
			string second = (*(++literals_begin)).str();
			if (strcmp(first.c_str(), second.c_str())) {
				throw invalid_argument("Invalid subtraction operation: trying to subtract two different values, differences in literals: " + first + " and " + second + "\n");
			}
			else {
				final_literal = (*literals_begin).str();
				return pair<double, string>(first_num - second_num, final_literal);
			}
		}
		else {
			throw invalid_argument("Invalid subtraction operation: trying to subtract two different values, only one literal\n");
		}
	}
	else if (regex_search(simple_operation, multiply)) {
		if (count == 0) {
			return pair<double, string>(first_num * second_num, "");
		}
		else if (count == 1) {
			string first_literal = (*literals_begin).str();
			return pair<double, string>(first_num * second_num, first_literal);
		}
		else if (count == 2) {
			string first_literal = (*literals_begin).str();
			string second_literal = (*(++literals_begin)).str();
			return mult_two_different(first_num, second_num, first_literal, second_literal);
		}
	}
	else if (regex_search(simple_operation, divide)) {
		if (count == 0) {
			return pair<double, string>(first_num / second_num, "");
		}
		else if (count == 1) {
			string first_literal = (*literals_begin).str();
			if (regex_search(simple_operation, literal_before_operator)) {
				return pair<double, string>(first_num / second_num, first_literal);
			}
			else {
				return divide_two_different(first_num, second_num, "", first_literal);
			}
		}
		else {
			string first_literal = (*literals_begin).str();
			string second_literal = (*(++literals_begin)).str();
			return divide_two_different(first_num, second_num, first_literal, second_literal);
		}
	}
	else {
		throw invalid_argument("Unknown operation\n");
	}
}


void calculate_nonparentheses_expression(string expression, pair<double, string>&result) {
	auto resolve_expression = [&expression,&result](regex& match_regex) {
		smatch found_exp;
		while (regex_search(expression, found_exp, match_regex, regex_constants::match_any)) {
			// cout << "Before: " << expression << endl;
			result = simple_calculate(found_exp[0].str());
			string to_swap = to_string(result.first) + result.second;
			expression = regex_replace(expression, match_regex, to_swap, regex_constants::format_first_only);
			// cout << "After: " << expression << endl << endl;
		}
	};
		regex multiplication("[A-Za-z0-9.,]+[*][A-Za-z0-9.,]+");
		regex division("[A-Za-z0-9.,]+[\\/][A-Za-z0-9.,]+");
		regex sum("[A-Za-z0-9.,]+[+][A-Za-z0-9.,]+");
		regex subtraction("[A-Za-z0-9.,]+[-][A-Za-z0-9.,]+");

		smatch found_exp;
		resolve_expression( multiplication);
		resolve_expression( division);
		resolve_expression(sum);
		resolve_expression(subtraction);
}



int main() {
	
	setlocale(LC_ALL, "Russian");
	
	string operation;
	cout << "¬ведите операцию" << endl;
	getline(cin, operation);
	pair<double, string> res;

	auto calc = [operation](string str) {
		
		auto resolve_parentheses = [operation](string& expression, pair<double, string>& result) {
			regex parentheses("([(])([^\\(\\)]+)([)])");
			smatch par_match;
			while (regex_search(expression, par_match, parentheses, regex_constants::match_any)) {
				calculate_nonparentheses_expression(par_match[2].str(), result);
				expression = regex_replace(expression, parentheses, to_string(result.first) + result.second, regex_constants::format_first_only);
			}
		};
		cout << "–азмер: " << sizeof(resolve_parentheses) << endl;
		pair<double, string> result;
		resolve_parentheses(str, result);
		calculate_nonparentheses_expression(str, result);
		return result;
	};
	
	try {
		res = calc(operation);
		cout << res.first << res.second << endl;
	}
	catch (invalid_argument ex) {
		cout << ex.what();
	}

	try {
		auto ptr0 = make_shared_ptr("mps");
		auto  ptr = make_shared_ptr1("kg");
		auto ptr1 = make_shared_ptr1("N");
		ptr0->print_info();
		ptr->print_info();
		ptr1->print_info();
	}
	catch (exception exc) {
		cout <<"Caugth error:"<< exc.what() << endl;
	}
	

	
	return -1;
}