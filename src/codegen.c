#include <stdio.h>
#include "../core/codegen.h"

void generate_tamizhi_code(ASTNode node, const char *output_filename) {
    FILE *fout = fopen(output_filename, "w");
    if (!fout) return;

    fprintf(fout, "main {\n");

    if (node.type == AST_PRINT) {
        fprintf(fout, "    call \"echo '%s'\" ;\n", node.value);
    } 
    // புதியது: Variable என்றால் தமிழி சிண்டாக்ஸில் எழுத
    else if (node.type == AST_ASSIGNMENT) {
        fprintf(fout, "    %s %s = %s ;\n", node.var_type, node.var_name, node.value);
    }

    fprintf(fout, "}\n");
    
    // Footer பிளாக்
    fprintf(fout, "\nfooter {\n    // End of program\n}\n");

    fclose(fout);
    printf("✅ மாஸ்! பைத்தான் கோட் வெற்றிகரமாக தமிழிக்கு மாற்றப்பட்டது: %s\n", output_filename);
}
