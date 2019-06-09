#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
extern char *yytext;
extern int yylineno;

#define INT 1
#define FLOAT 2

typedef enum __NodeType {
    L_MIN = 1000,
    L_AUTO,
    L_BOOL,
    L_BREAK,
    L_CASE,
    L_CHAR,
    L_CONST,
    L_CONTINUE,
    L_DEFAULT,
    L_DO,
    L_DOUBLE,
    L_ELSE,
    L_ENUM,
    L_EXTERN,
    L_FLOAT,
    L_FOR,
    L_GOTO,
    L_IF,
    L_INT,
    L_REGISTER,
    L_RETURN,
    L_LONG,
    L_SIGNED,
    L_SIZEOF,
    L_STATIC,
    L_STRUCT,
    L_SWITCH,
    L_TYPEDEF,
    L_UNION,
    L_UNSIGNED,
    L_VOID,
    L_VOLATILE,
    L_WHILE,
    L_TRUE,
    L_FALSE,
    L_IDENTIFIER,
    L_CONSTANT_INT,
    L_CONSTANT_DOUBLE,
    L_STRING_LITERAL,
    L_ASSIGN_RIGHT,
    L_ASSIGN_LEFT,
    L_ASSIGN_ADD,
    L_ASSIGN_SUB,
    L_ASSIGN_MUL,
    L_ASSIGN_DIV,
    L_ASSIGN_MOD,
    L_ASSIGN_AND,
    L_ASSIGN_XOR,
    L_ASSIGN_OR,
    L_OP_RIGHT,
    L_OP_LEFT,
    L_OP_INC,
    L_OP_DEC,
    L_OP_PTR,
    L_OP_AND,
    L_OP_OR,
    L_OP_LE,
    L_OP_GE,
    L_OP_EQ,
    L_OP_NE,
    L_MAX,

///////////////////////////////////////////////////////////////

    UNT_MIN = 2000,
    EXTERNAL_DECLARATION,
    SELECTION_STATEMENT,
    PARAMETER_LIST,
    ENUM_SPECIFIER,
    TYPE_QUALIFIER,
    POSTFIX_EXPRESSION,
    INIT_DECLARATOR_LIST,
    PROGRAM,
    CONDITIONAL_EXPRESSION,
    IDENTIFIER_LIST,
    ITERATION_STATEMENT,
    LOGICAL_OR_EXPRESSION,
    ADDITIVE_EXPRESSION,
    STORAGE_CLASS_SPECIFIER,
    STRUCT_DECLARATOR,
    STRUCT_DECLARATION,
    UNARY_EXPRESSION,
    EXCLUSIVE_OR_EXPRESSION,
    TYPE_QUALIFIER_LIST,
    LABELED_STATEMENT,
    ABSTRACT_DECLARATOR,
    SPECIFIER_QUALIFIER_LIST,
    STRUCT_DECLARATION_LIST,
    UNARY_OPERATOR,
    DECLARATION_SPECIFIERS,
    CAST_EXPRESSION,
    DECLARATOR,
    EXPRESSION,
    DIRECT_DECLARATOR,
    PRIMARY_EXPRESSION,
    JUMP_STATEMENT,
    TRANSLATION_UNIT,
    TYPE_SPECIFIER,
    ENUMERATOR,
    ASSIGNMENT_EXPRESSION,
    COMPOUND_STATEMENT,
    INCLUSIVE_OR_EXPRESSION,
    PARAMETER_DECLARATION,
    MULTIPLICATIVE_EXPRESSION,
    INIT_DECLARATOR,
    ARGUMENT_EXPRESSION_LIST,
    CONSTANT_EXPRESSION,
    ENUMERATOR_LIST,
    RELATIONAL_EXPRESSION,
    STATEMENT,
    STATEMENT_LIST,
    LOGICAL_AND_EXPRESSION,
    DECLARATION_LIST,
    EQUALITY_EXPRESSION,
    EXPRESSION_STATEMENT,
    STRUCT_OR_UNION,
    FUNCTION_DEFINITION,
    PARAMETER_TYPE_LIST,
    POINTER,
    TYPE,
    INITIALIZER,
    INITIALIZER_LIST,
    ASSIGNMENT_OPERATOR,
    DECLARATION,
    DIRECT_ABSTRACT_DECLARATOR,
    STRUCT_DECLARATOR_LIST,
    SHIFT_EXPRESSION,
    AND_EXPRESSION,
    UNT_MAX
} NodeType;

typedef struct __GrammarTree
{
    int id;
    int line;
    NodeType type;
    void *content;

    int num;
    struct __GrammarTree **child;
} GrammarTree;

extern GrammarTree *root;

GrammarTree* createTree(NodeType type, int num, ...);
GrammarTree* createLeaf(NodeType type, int pos);
void eval(GrammarTree *head, int level);
void deleteGrammarTree(GrammarTree *node);

#endif
