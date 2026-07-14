#include <stdio.h>
#include "../core/codegen.h"

void generate_tamizhi_code(ASTNode node, const char *output_filename) {
    FILE *fout = fopen(output_filename, "w");
    if (!fout) {
        printf("Error: ஃபைலை உருவாக்க முடியவில்லை!\n");
        return;
    }

    // தமிழி மொழியின் ஆரம்பக் கட்டமைப்பு
    fprintf(fout, "main {\n");

    // AST Node-ல் இருப்பது print கமாண்ட் என்றால்
    if (node.type == AST_PRINT) {
        fprintf(fout, "    call \"echo '%s'\" ;\n", node.value);
    }

    // தமிழி மொழியின் முடிவுக் கட்டமைப்பு
    fprintf(fout, "}\n");

    fclose(fout);
    printf("✅ மாஸ்! பைத்தான் கோட் வெற்றிகரமாக தமிழிக்கு மாற்றப்பட்டது: %s\n", output_filename);
}
